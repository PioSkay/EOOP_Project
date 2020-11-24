#include "../include/Team.hpp"
Team::Team(unsigned int team_ID, std::string& name, std::string& short_name): team_ID(team_ID), name(name), short_name(short_name){}
Team::Team(unsigned int team_ID, std::string& name, std::string& short_name, std::initializer_list<std::string> sponsors): team_ID(team_ID), name(name), short_name(short_name){
    fill_list(sponsors);
}
std::string Team::construct_data(const std::string& text, const std::string& data){
    size_t pos = text.find(data + ":");
    size_t pos_2 = text.find(";",pos+1);
    if(pos == std::string::npos){
        throw std::invalid_argument("Team: " + data + " not found!");
    }
    if(pos_2 == std::string::npos or (pos + data.size()+1) - pos_2 == 0){
        throw std::invalid_argument("Team: Wrong " + data + "!");
    }
    return text.substr(pos + data.size()+1, pos_2 - (pos + data.size()+1));
}
Team::Team(const std::string &loc){
    size_t pos = loc.find("Sponsors:");
    size_t pos_2;
    if(pos != std::string::npos){
        pos_2  = loc.find(";",pos+1);
        if(pos_2 == std::string::npos or (pos + 9) - pos_2 == 0){
            throw std::invalid_argument("Team: Wrong sponsors list!");
        }
        std::string sponsors = loc.substr(pos + 9, pos_2 - (pos + 9));
        fill_list(sponsors);
    }
    //finding name
    Team::name = construct_data(loc, "Name");
    //finding id
    Team::team_ID = stoi(construct_data(loc, "ID"));
    //finding short name
    Team::short_name = construct_data(loc, "Short_Name");
}
void Team::fill_list(std::string loc){
    size_t pos = 0;
    for(size_t i = loc.find(",",pos+1); i != std::string::npos; i = loc.find(",",pos+1)){
        Sponsors.push_back(loc.substr(pos, loc.find(",",pos+1) - pos));
        pos = i + 1;
    }
    Sponsors.push_back(loc.substr(pos, loc.find(",",pos+1) - pos));
}
Team::~Team(){
    Sponsors.clear();
}
void Team::fill_list(std::initializer_list<std::string> sponsors){
    for(std::initializer_list<std::string>::iterator i = sponsors.begin(); i != sponsors.end(); i++)
    {
        Sponsors.push_front(*i);
    }
}
void Team::Add_sponsor(std::initializer_list<std::string> sponsors){
    fill_list(sponsors);
}
void Team::Add_sponsor(std::string sponsor){
    Sponsors.push_front(sponsor);
}
void Team::info(std::ostream &out) const{
    out <<"ID: " << team_ID <<" Name: "<< name <<" Short_Name: "<< short_name;
    if(Sponsors.size() > 0){
        out << " Sponsors:";
        for(std::list<std::string>::const_iterator it = Sponsors.begin(); it != Sponsors.end(); it++){
            out<<*it << " ";
        }
    }
}
std::ostream& operator<<(std::ostream& out, const Team &x){
    x.info(out);
    return out;
}
