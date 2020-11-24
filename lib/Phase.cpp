#include "../include/Phase.hpp"
Phase::Phase(unsigned int stage_ID, std::string& Course, float distance, enum Type Type, std::list<Cyclist>& cyclists): stage_ID(stage_ID), Course(Course), distance(distance), type(Type){
    Finish_Registration(cyclists);
    Leader = nullptr; Winner = nullptr;
}
std::string Phase::construct_data(const std::string& text, const std::string& data){
    size_t pos = text.find(data + ":");
    size_t pos_2 = text.find(";",pos+1);
    if(pos == std::string::npos){
        throw std::invalid_argument("Phase: " + data + " not found!");
    }
    if(pos_2 == std::string::npos or (pos + data.size()+1) - pos_2 == 0){
        throw std::invalid_argument("Phase: " + data + " content not found!");
    }
    return text.substr(pos + data.size()+1, pos_2 - (pos + data.size()+1));
}
Phase::Phase(const std::string& text, std::list<Cyclist>& cyclists){
    Leader = nullptr; Winner = nullptr;
    Finish_Registration(cyclists);
    //id
    stage_ID = stoi(construct_data(text, "ID"));
    //distance
    distance = stof(construct_data(text, "Distance"));
    //course
    Course = construct_data(text, "Course");
    //type
    std::string t = construct_data(text, "Type");
    if(t == "Mountain_Stage" or t == "Mountain Stage"){
        type = Mountain_Stage;
    } else if(t == "Hilly_Stage" or t == "Hilly Stage"){
        type = Hilly_Stage;
    } else if(t == "Individual_Time_Trial" or t == "Individual Time Trial"){
        type = Individual_Time_Trial;
    } else if(t == "Flat_Stage" or t == "Flat Stage"){
        type = Flat_Stage;
    } else {
        throw std::invalid_argument("Phase: Wrong Type!");
    }
}
void Phase::Is_Phase_Done(){
    unsigned int elem = 0;
    for(std::set<Result>::iterator it = Results.begin(); it != Results.end(); it++){
        if(it->Points_Data() != -1){
            elem++;
        }
    }
    if(elem == Results.size()){
        status = Done;
    }
}
void Phase::Finish_Registration(std::list<Cyclist>& cyclists){
    if(Results.empty() != true){
        throw std::invalid_argument("Phase: Results already filled!");
    }
    for(std::list<Cyclist>::iterator it = cyclists.begin(); it != cyclists.end(); it++){
        Results.insert(Result(&(*it)));
    }
    status = Undone;
}
void Phase::Enter_Results(const unsigned int id, const int Time, const int Additional_Time){
    bool find = false;
    for(std::set<Result>::iterator it = Results.begin(); it != Results.end(); it++){
        if(it->Cyc_Id() == id){
            Result x(it->Cyclist_Data(), Time, Additional_Time, (Time + Additional_Time)/distance);
            Results.erase(it);
            Results.insert(x);
            find = true;
        }
    }
    if(find == false){
        throw std::invalid_argument("Phase: Wrong ID in results!");
    }
}
void Phase::Enter_Results(const std::string loc){
    std::set<Result> new_set;
    std::ifstream file(loc);
    unsigned int ID;
    int time, additional_time = 0;
    size_t pos, pos_2;
    std::string line;
    if(file.is_open()){
        while(getline(file, line)){
            if(line[0] != '/' and line[1] != '/'){
                ID = (unsigned int)stoi(construct_data(line, "ID"));
                time = stoi(construct_data(line, "Time"));
                pos = line.find("Additional_Time:");
                pos_2 = line.find(";",pos+1);
                if(pos != std::string::npos){
                    if(pos_2 == std::string::npos){
                       throw std::invalid_argument("Phase: Wrong Cyclist Additional_Time!");
                    }
                    additional_time = stoi(line.substr(pos + 5, pos_2 - (pos + 5)));
                }
                Enter_Results(ID, time, additional_time);
            }
        }
    } else{
        throw std::invalid_argument("Phase: Results file not found!");
    }
    Is_Phase_Done();
    file.close();
}
void Phase::Set_Led(Cyclist* Leader){
    if(Phase::Leader == nullptr){
        Phase::Leader = Leader;
    }
}
void Phase::lock(){
    if(status == Done){
        Winner = Results.begin()->Cyclist_Data();
        status = Locked;
    } else {
        throw std::invalid_argument("Phase: Phase can not be locked!");
    }
}
bool Phase::is_done() const{
    return status == Done;
}
bool Phase::is_locked() const{
    return status == Locked;
}
int Phase::player_points(const unsigned int ID){
    for(std::set<Result>::iterator it = Results.begin(); it != Results.end(); it++){
        if(it->Cyc_Id() == ID){
            return it->Points_Data();
        }
    }
    throw std::invalid_argument("Phase/player_points: Player's ID not found!");
}
void Phase::info_basic(std::ostream &out) const{
    out << "ID:" << stage_ID << ", Disctance: " << distance << "km, Course: " << Course << ", Type: ";
    if(type == Mountain_Stage){
        out << "Mountain Stage,";
    } else if(type == Hilly_Stage){
        out << "Hilly Stage,";
    } else if(type == Individual_Time_Trial){
        out << "Individual Time Trial,";
    } else {
        out << "Flat Stage,";
    }
    out<<" Status: ";
    if(status == Done){
        out << "Done";
    } else if(status == Undone){
        out<< "Undone";
    } else {
        out << "Locked";
    }
}
void Phase::info_advanced(std::ostream &out) const{
    info_basic(out);
    out<<std::endl;
    if(Winner != nullptr){
        out<<"Winner:"<<std::endl;
        out<<*Winner<<std::endl;
    }
    if(Leader != nullptr){
        out<<"Leader:"<<std::endl;
        out<<*Leader<<std::endl;
    }
    if(Results.empty() == false and status != Undone){
        out<<"Results:";
        for(std::set<Result>::iterator it = Results.begin(); it != Results.end(); it++){
            out << std::endl;
            out << *it;
        }
    } else {
        out<<"Phase undone!"<<std::endl;
    }
}
std::ostream& operator<<(std::ostream &out, const Phase &x){
    x.info_basic(out);
    x.info_advanced(out);
    return out;
}
