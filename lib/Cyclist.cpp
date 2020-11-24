#include "../include/Cyclist.hpp"
Cyclist::Cyclist(unsigned int Unique_ID, Team* cyclist_team, int Age, std::string& FirstName, std::string& LastName, std::string& Nation, std::string& Story): Unique_ID(Unique_ID), Age(Age), FirstName(FirstName), LastName(LastName), Nation(Nation), Story(Story), cyclist_team(cyclist_team){}
Cyclist::Cyclist(unsigned int Unique_ID, int Age, std::string& FirstName, std::string& LastName, std::string& Nation, std::string& Story): Unique_ID(Unique_ID), Age(Age), FirstName(FirstName), LastName(LastName), Nation(Nation), Story(Story),cyclist_team(nullptr){};
std::string Cyclist::construct_data(const std::string& text, const std::string& data){
    size_t pos = text.find(data + ":");
    size_t pos_2 = text.find(";",pos+1);
    if(pos == std::string::npos){
        throw std::invalid_argument("Cyclist: " + data + " not found!");
    }
    if(pos_2 == std::string::npos or (pos + data.size()+1) - pos_2 == 0){
        throw std::invalid_argument("Cyclist: " + data + " content not found!");
    }
    return text.substr(pos + data.size()+1, pos_2 - (pos + data.size()+1));
}
Cyclist::Cyclist(const std::string& text, Team* team){
    general_time = 0;
    cyclist_team = team;
    //finding id inside of the line
    Unique_ID = stoi(construct_data(text, "ID"));
    //finding Age inside of the line
    Age = stoi(construct_data(text, "Age"));
    if(Age <= 0){
        throw std::invalid_argument("Cyclist: Wrong age!");
    }
    //finding Name inside of the line
    FirstName = construct_data(text, "Name");
    //finding Surname inside of the line
    LastName = construct_data(text, "Surname");
    //finding Surname inside of the line
    Nation = construct_data(text, "Nation");
    //finding Nation inside of the line
    size_t pos = text.find("Story:");
    size_t pos_2 = text.find(";",pos+1);
    if(pos != std::string::npos){
        if(pos_2 == std::string::npos or (pos + 6) - pos_2 == 0){
            throw std::invalid_argument("Cyclist: Story content not found!");
        }
        Story = text.substr(pos + 6, pos_2 - (pos + 6));
    }
}
Cyclist::~Cyclist(){
}
unsigned int Cyclist::Cyclist_Team_ID() const{
    return cyclist_team->Team_ID();
}
std::string Cyclist::Cyclist_Team_Name() const{
    return cyclist_team->Team_Name();
}
std::string Cyclist::Cyclist_Team_Short_Name() const{
    return cyclist_team->Team_SName();
}
unsigned int Cyclist::Cyclist_ID() const{
    return Unique_ID;
}
std::string Cyclist::Cyclist_Name() const{
    return FirstName;
}

std::string Cyclist::Cyclist_SecondName() const{
    return LastName;
}

int Cyclist::Cyclist_Age() const{
    return Age;
}

std::string Cyclist::Cyclist_Nation() const{
    return Nation;
}

std::string Cyclist::Cyclist_Story() const{
    return Story;
}
Team* Cyclist::Cyclist_Team() const{
    return cyclist_team;
}
void Cyclist::basic_info(std::ostream &out) const{
    out << "Name: " << FirstName << ", Surname: " << LastName << ", Age: " << Age;
}
void Cyclist::info(std::ostream &out) const{
    basic_info(out);
    if(Story.empty() == false){
        out << " Story: " << Story;
    }
    if(cyclist_team != nullptr){
        out << " Cyclist Team:" << *cyclist_team;
    }
}
std::ostream& operator<<(std::ostream& out, const Cyclist &x){
    x.info(out);
    return out;
}
