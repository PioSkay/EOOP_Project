#include "../include/Tournament.hpp"
std::string Tournament::construct_data(const std::string& text, const std::string& data){
    size_t pos = text.find(data + ":");
    size_t pos_2 = text.find(";",pos+1);
    if(pos == std::string::npos){
        throw std::invalid_argument("Tournament: " + data + " not found!");
    }
    if(pos_2 == std::string::npos or (pos + data.size()+1) - pos_2 == 0){
        throw std::invalid_argument("Tournament: " + data + " content not found!");
    }
    return text.substr(pos + data.size()+1, pos_2 - (pos + data.size()+1));
}
void Tournament::is_ok_line(std::string& target, std::string& line, std::string msg){
    if(!is_name_correct(line)){
        throw std::invalid_argument("Tournament: Incorrect "+msg+" file name!");
    }
    msg[0] = toupper(msg[0]);
    if(target.size()!=0){
        throw std::invalid_argument("Tournament: "+msg+" path already exists!");
    }
    target = line;
}
template<class Iter, class Function, class Class>
void Tournament::output(std::ostream& out, Iter begin, Iter end, Function fun, void (Class::*data)(std::ostream& out) const){
    while(begin != end){
        if(fun(*begin)){
            (*begin.*data)(out);
            out << std::endl;
        }
      ++begin;
    }
}
template <typename Class, typename Var>
void Tournament::operations(std::ostream& out, std::list<Class>& list, const Var& a, Var (Class::*f)() const, const enum Oper& op, const bool& access, void (Class::*data)(std::ostream& out) const){
    if(op == EQUAL){
        output(out, list.begin(), list.end(), [a, f](const Class& b){return a == (b.*f)();}, data);
    } else{
        if(access == 1){
            if(op == GRATER){
                output(out, list.begin(), list.end(), [a, f](const Class& b){return a < (b.*f)();}, data);
            } else if(op == GRATER_EQUAL){
                output(out, list.begin(), list.end(), [a, f](const Class& b){return a <= (b.*f)();}, data);
            } else if(op == LOWER){
                output(out, list.begin(), list.end(), [a, f](const Class& b){return a > (b.*f)();}, data);
            } else if(op == LOWER_EQUAL){
                output(out, list.begin(), list.end(), [a, f](const Class& b){return a >= (b.*f)();}, data);
            }
        } else {
            throw std::invalid_argument("Wrong operation parameters!");
        }
    }
}
int Tournament::converter(const std::vector<std::string>& elements, const std::string& text) const{
    for(unsigned long i = 0; i < elements.size(); i++){
        if(elements[i] == text) return (int)i;
    }
    throw std::invalid_argument("Tournament converter: Name not found!");
}
void Tournament::data_proceed(std::ostream& out, const enum What& w, const enum Operations& o, const enum Oper& op, const std::string& arg){
    if(w == CYCLIST){
        if(o == OP_NONE){
            output(out, Cyclists.begin(), Cyclists.end(), [](const Cyclist& b){return true;}, &Cyclist::info);
        } else if(o == ID){
            operations(out, Cyclists, (unsigned int)stoi(arg), &Cyclist::Cyclist_ID, op, 1, &Cyclist::basic_info);
        } else if(o == AGE){
            operations(out, Cyclists, (int)stoi(arg), &Cyclist::Cyclist_Age, op, 1, &Cyclist::basic_info);
        } else if(o == FIRSTNAME){
            operations(out, Cyclists, arg, &Cyclist::Cyclist_Name, op, 0, &Cyclist::basic_info);
        } else if(o == LASTNAME){
            operations(out, Cyclists, arg, &Cyclist::Cyclist_SecondName, op, 0, &Cyclist::basic_info);
        } else if(o == NATION){
            operations(out, Cyclists, arg, &Cyclist::Cyclist_Nation, op, 0, &Cyclist::basic_info);
        } else if(o == TEAM_ID){
            operations(out, Cyclists, (unsigned int)stoi(arg), &Cyclist::Cyclist_Team_ID, op, 1, &Cyclist::info);
        } else if(o == TEAM_NAME){
            operations(out, Cyclists, arg, &Cyclist::Cyclist_Team_Name, op, 0, &Cyclist::info);
        } else if(o == TEAM_SHORT_NAME){
            operations(out, Cyclists, arg, &Cyclist::Cyclist_Team_Short_Name, op, 0, &Cyclist::info);
        }
    } else if(w == TEAM){
        if(o == OP_NONE){
            output(out, Teams.begin(), Teams.end(), [](const Team& b){return true;}, &Team::info);
        } else if(o == ID or o == TEAM_ID){
            operations(out, Teams, (unsigned int)stoi(arg), &Team::Team_ID, op, 1, &Team::info);
        } else if(o == TEAM_NAME){
            operations(out, Teams, arg, &Team::Team_Name, op, 0, &Team::info);
        } else if(o == TEAM_SHORT_NAME){
            operations(out, Teams, arg, &Team::Team_SName, op, 0, &Team::info);
        }
    } else if(w == PHASE){
        if(o == OP_NONE){
            output(out, Phases.begin(), Phases.end(), [](const Phase& b){return true;}, &Phase::info_basic);
        } else if(o == PHASE_TYPE){
            operations(out, Phases, (enum Type)converter(Type_As_String, arg), &Phase::Phase_Type, op, 0, &Phase::info_basic);
        } else if(o == ID){
            operations(out, Phases, (unsigned int)stoi(arg), &Phase::phase_ID, op, 1, &Phase::info_basic);
        } else if(o == PHASE_ID_ADVANCED){
            operations(out, Phases, (unsigned int)stoi(arg), &Phase::phase_ID, op, 0, &Phase::info_advanced);
        } else if(o == PHASE_STATUS){
            operations(out, Phases, (enum Status)converter(Status_As_String, arg), &Phase::Phase_Status, op, 0, &Phase::info_basic);
        }
    } else if(w == GENERAL){
        out<<*this;
    }
}
Tournament::Tournament(const std::string& loc): Stage(Registration){
    std::ifstream file(loc + "config.txt");
    std::string line;
    Files_Loc files;
    if(file.is_open()){
        while(getline(file, line, ':')){
            if(line == "Teams"){
                getline(file, line);
                is_ok_line(files.teams_loc, line, "teams");
            } else if(line == "Cyclist"){
                getline(file, line);
                is_ok_line(files.cyclist_loc, line, "cyclist");
            } else if(line == "Phase"){
                getline(file, line);
                is_ok_line(files.phase_loc, line, "phase");
            } else if(line == "Results"){
                getline(file, line);
                is_ok_line(files.results_loc, line, "results");
            } else if(line == "General"){
                getline(file, line);
                is_ok_line(files.general_loc, line, "general");
            }
        }
        file.close();
    } else {
        throw std::invalid_argument("Tournament: Config file not found!");
    }
    if(files.cyclist_loc.size() == 0 or files.phase_loc.size() == 0 or files.general_loc.size() == 0){
        throw std::invalid_argument("Tournament: cyclist/phase/general path not found!");
    }
    add(TEAM, &Tournament::add_team, *this, loc+files.teams_loc);
    add(CYCLIST, &Tournament::add_cyclist, *this ,loc+files.cyclist_loc);
    if(files.general_loc.empty() != true){
        add(GENERAL, &Tournament::add_gerneral_info_file, *this, loc+files.general_loc);
    }
    if(files.phase_loc.empty() != true){
        add(PHASE, &Tournament::add_phase, *this, loc+files.phase_loc);
    }
    if(files.results_loc.empty() != true){
        add_results(loc,files.results_loc);
    }
}
Tournament::~Tournament(){
    Cyclists.clear();
    Phases.clear();
    Teams.clear();
}
bool Tournament::is_name_correct(std::string &text){
    if(text == ""){
        return false;
    }
    for(unsigned long i = 0;  i < text.size(); i++){
        if((((int)text[i] < (int)'a' or text[i] > (int)'z') and ((int)text[i] < (int)'A' or text[i] > (int)'Z')) and text[i] != '.'){
            return false;
        }
    }
    if(text.find(".txt") == std::string::npos){
        text = text + ".txt";
    }
    text = "/" + text;
    return true;
}
void Tournament::add_general_info(const std::string& text){
    Stage = Registration;
    Name = construct_data(text, "Name");
    Winner_Blue.cash_change(stof(construct_data(text, "Blue")));
    Winner_Green.cash_change(stof(construct_data(text, "Green")));
    Winner_Red.cash_change(stof(construct_data(text, "Red")));
}
void Tournament::add_gerneral_info_file(const std::string& line){
    add_general_info(line);
}
void Tournament::add(const enum What& what, void (Tournament::*f)(const std::string& line), Tournament& x, const std::string& path){
    std::ifstream file(path);
    std::string line;
    if(file.is_open()){
        while(getline(file, line)){
            if(line[0] != '/' and line[1] != '/'){
                (x.*f)(line);
            }
        }
    } else {
        throw std::invalid_argument("Tournament: " + What_Text[what] + " file not found!");
    }
}
void Tournament::add_cyclist(const Cyclist &cyclist){
    Reg_Check();
    if(Cyclist_Unique(cyclist.Cyclist_ID()) == false){
        throw std::invalid_argument("Tournament: Cyclist not unique!");
    }
    Cyclists.push_back(cyclist);
}
void Tournament::add_cyclist(const std::string& line){
    Reg_Check();
    size_t pos = line.find("Team:");
    size_t pos_2 = line.find(";",pos+1);
    if(pos != std::string::npos){
        if(pos_2 == std::string::npos){
            throw std::invalid_argument("Tournament: Team ID not found!");
        }
        Cyclist x(line, find_team(stoi(line.substr(pos + 5, pos_2 - (pos + 5)))));
        if(Cyclist_Unique(x.Cyclist_ID()) == false){
            throw std::invalid_argument("Tournament: Cyclist not unique!");
        }
        Cyclists.push_back(x);
    } else {
        Cyclist x(line, nullptr);
        if(Cyclist_Unique(x.Cyclist_ID()) == false){
            throw std::invalid_argument("Tournament: Cyclist not unique!");
        }
        Cyclists.push_back(x);
    }
}
void Tournament::add_team(const Team& team){
    Reg_Check();
    if(Team_Unique(team.Team_ID()) == false){
        throw std::invalid_argument("Tournament: Team not unique!");
    }
    Teams.push_back(team);
}
void Tournament::add_team(const std::string& line){
    Reg_Check();
    Team x(line);
    if(Team_Unique(x.Team_ID()) == false){
        throw std::invalid_argument("Tournament: Team not unique!");
    }
    Teams.push_back(x);
}
void Tournament::add_phase(const std::string& line){
    Reg_Check();
    Phase x(line, Cyclists);
    if(Phase_Unique(x.phase_ID()) == false){
        throw std::invalid_argument("Tournament: Phase not unique!");
    }
    Phases.push_back(x);
}
void Tournament::add_results(const std::string& loc, const std::string& name){
    Stage = In_progress;
    std::ifstream file(loc+name);
    std::string line;
    unsigned int ID;
    if(file.is_open()){
        while(getline(file, line, ':')){
            ID = (unsigned int)stoi(line);
            if(Phase_Unique(ID)){
                throw std::invalid_argument("Tournament: Phase ID not found while filling the results!");
            }
            getline(file, line, ';');
            if(!is_name_correct(line)){
                throw std::invalid_argument("Tournament: Wrong results file name!");
            }
            for(std::list<Phase>::iterator it = Phases.begin(); it != Phases.end(); it++){
                if(it->phase_ID() == ID){
                    if(it == Phases.begin()){
                        it->Enter_Results(loc+line);
                    } else {
                        prev(it)->lock();
                        if(Can_Be_Filled(ID) == false){
                            throw std::invalid_argument("Tournament: Phase results can't be filled!");
                        }
                        it->Enter_Results(loc+line);
                        calculate();
                    }
                }
            }
        }
    } else {
        throw std::invalid_argument("Tournament: Config file for results not found!");
    }
}
void Tournament::calculate(){
    std::list<Result> curr;
    for(std::list<Cyclist>::iterator it = Cyclists.begin(); it != Cyclists.end(); it++){
        Result x(&(*it), 0, 0, 0);
        curr.push_back(x);
    }
    for(std::list<Phase>::iterator a = Phases.begin(); a != Phases.end() and (a->is_locked() == true or a->is_done() == true); a++){
        for(std::list<Result>::iterator it = curr.begin(); it != curr.end(); it++){
            it->Points_Change(it->Points_Data() + a->player_points(it->Cyc_Id()));
        }
        curr.sort();
        a->Set_Led(curr.begin()->Cyclist_Data());
    }
}
void Tournament::lock_phases(){
    unsigned long inf = 0;
    for(std::list<Phase>::iterator it = Phases.begin(); it != Phases.end(); it++){
        if(it->is_done() == true){
            it->lock();
        }
        if(it->is_locked() == true){
            inf++;
        }
    }
    if(inf == Phases.size()){
        calculate();
        final_calc();
    }
}
Team* Tournament::find_team(const unsigned int ID){
    for(std::list<Team>::iterator it = Teams.begin(); it != Teams.end(); it++){
        if(it->Team_ID() == ID){
            return &(*it);
        }
    }
    throw std::invalid_argument("Tournament: Team ID not found!");
}
bool Tournament::Team_Unique(const unsigned int ID) const{
    for(std::list<Team>::const_iterator it = Teams.begin(); it != Teams.end(); it++){
        if(it->Team_ID() == ID){
            return false;
        }
    }
    return true;
}
bool Tournament::Cyclist_Unique(const unsigned int ID) const{
    for(std::list<Cyclist>::const_iterator it = Cyclists.begin(); it != Cyclists.end(); it++){
        if(it->Cyclist_ID() == ID){
            return false;
        }
    }
    return true;
}
bool Tournament::Phase_Unique(const unsigned int ID) const{
    for(std::list<Phase>::const_iterator it = Phases.begin(); it != Phases.end(); it++){
        if(it->phase_ID() == ID){
            return false;
        }
    }
    return true;
}
bool Tournament::Can_Be_Filled(const unsigned int ID) const{
    for(std::list<Phase>::const_iterator it = Phases.begin(); it != Phases.end(); it++){
        if(it->phase_ID() == ID){
            if(it == Phases.begin()){
                return true;
            } else if(it->is_locked() == false){
                return prev(it)->is_locked() == true;
            } else {
                return false;
            }
        }
    }
    return false;
}
std::list<Result> Tournament::Calc_Based_On_Type(Type type){
    std::list<Result> curr;
    for(std::list<Cyclist>::iterator it = Cyclists.begin(); it != Cyclists.end(); it++){
        Result x(&(*it), 0, 0, 0);
        curr.push_back(x);
    }
    for(std::list<Phase>::iterator a = Phases.begin(); a != Phases.end() and (a->is_locked() == true or a->is_done() == true); a++){
        if(a->Phase_Type() == type){
            for(std::list<Result>::iterator it = curr.begin(); it != curr.end(); it++){
                it->Points_Change(it->Points_Data() + a->player_points(it->Cyc_Id()));
            }
        }
    }
    curr.sort();
    return curr;
}
void Tournament::final_calc(){
    std::list<Result> x;
    x = Calc_Based_On_Type(Mountain_Stage);
    Winner_Blue.Set_Cyclist(x.begin()->Cyclist_Data());
    x = Calc_Based_On_Type(Individual_Time_Trial);
    Winner_Red.Set_Cyclist(x.begin()->Cyclist_Data());
    if(prev(Phases.end())->is_locked() == true){
        Winner_Green.Set_Cyclist(prev(Phases.end())->Leader_Data());
        Stage = Tournament_Done;
    }
    x.clear();
}
void Tournament::Reg_Check(){
    if(Stage != Registration){
        throw std::invalid_argument("Tournament: Registration is over! Can not add new phase/cyclist!");
    }
}
void Tournament::Show(const enum What& w, const enum Operations& o, const enum Oper& op, const std::string& arg){
    data_proceed(std::cout, w, o, op, arg);
}
void Tournament::Save(const std::string& path, const enum What& w, const enum Operations& o, const enum Oper& op, const std::string& arg){
    std::fstream file;
    file.open(path, std::ios::out | std::ios::trunc);
    data_proceed(file, w, o, op, arg);
}
void Tournament::info(std::ostream& out) const{
    out.precision(2);
    out << std::fixed << "Name: " <<Name<<", "<<"Green: "<<Winner_Green.cash()<<", "<<"Blue: "<<Winner_Blue.cash()<<", "<<"Red: "<<Winner_Red.cash() << std::endl;
    if(Winner_Green.Cyclist_Data() != nullptr){
        out<<"Winner of Green: "<<*Winner_Green.Cyclist_Data()<<std::endl;
    }
    if(Winner_Blue.Cyclist_Data() != nullptr){
        out<<"Winner of Blue: "<<*Winner_Blue.Cyclist_Data()<<std::endl;
    }
    if(Winner_Red.Cyclist_Data() != nullptr){
        out<<"Winner of Red: "<<*Winner_Red.Cyclist_Data()<<std::endl;
    }
    out<<"Status: ";
    if(Stage == Registration){
        out<<"Registration"<<std::endl;
    } else if(Stage == In_progress){
        out<<"In progress"<<std::endl;
    } else {
        out<<"Done"<<std::endl;
    }
}
std::ostream& operator<<(std::ostream& out, const Tournament& x){
    x.info(out);
    return out;
}
