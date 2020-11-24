#ifndef player_hpp
#define player_hpp
#include <string>
#include <iostream>
#include "Team.hpp"
class Cyclist{
    private:
        unsigned int Unique_ID;
        int Age;
        std::string FirstName;
        std::string LastName;
        std::string Nation;
        //Story of previous achivements of the player
        std::string Story;
        //general time in whole run(has to be updated)
        int general_time;
        //player cannot enter the run witout a team (according to rules)
        Team* cyclist_team;
        std::string construct_data(const std::string& text, const std::string& data);
    public:
        Cyclist(unsigned int Unique_ID, Team* player_team, int age, std::string& FirstName, std::string& LastName, std::string& Nation, std::string& Story);
        Cyclist(unsigned int Unique_ID, int age, std::string& FirstName, std::string& LastName, std::string& Nation, std::string& Story);
        Cyclist(const std::string& text, Team* team);
        ~Cyclist();
        unsigned int Cyclist_Team_ID() const;
        std::string Cyclist_Team_Name() const;
        std::string Cyclist_Team_Short_Name() const;
        //returns unique id
        unsigned int Cyclist_ID() const;
        //returns name or or reference to an object
        std::string Cyclist_Name() const;
        void Change_Cyclist_Name(const std::string name);
        //returns secondname or reference to an object
        std::string Cyclist_SecondName() const;
        void Change_Cyclist_SecondName(const std::string sname);
        //returns age or reference to an object
        int Cyclist_Age() const;
        void Change_Cyclist_Age(const std::string age);
        //returns nation or reference to an object
        std::string Cyclist_Nation() const;
        void Change_Cyclist_Nation(const std::string nation);
        //returns Story or reference to an object
        std::string Cyclist_Story() const;
        void Change_Cyclist_Story(const std::string story);
        //assagin to the team or return team
        Team* Cyclist_Team() const;
        void change_team(Team* team);
        //general information about the player
        void basic_info(std::ostream &out) const;
        void info(std::ostream &out) const;
        friend std::ostream& operator<<(std::ostream& out, const Cyclist &x);
};
#endif /* player_hpp */
