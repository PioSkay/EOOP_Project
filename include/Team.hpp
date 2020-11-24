#ifndef Team_hpp
#define Team_hpp

#include <iostream>
#include <string>
#include <initializer_list>
#include <list>
class Team{
    private:
        unsigned int team_ID;
        std::string name;
        std::string short_name;
        std::list<std::string> Sponsors;
        void fill_list(std::initializer_list<std::string> sponsors);
        void fill_list(std::string loc);
        std::string construct_data(const std::string& text, const std::string& data);
    public:
        Team(unsigned int team_ID, std::string& name, std::string& short_name);
        Team(unsigned int team_ID, std::string& name, std::string& short_name, std::initializer_list<std::string> sponsors);
        Team(const std::string &loc);
        ~Team();
        //Team id
        unsigned int Team_ID() const{return team_ID;};
        std::string Team_Name() const{return name;};
        std::string Team_SName() const{return short_name;};
        //Adding sponsors
        void Add_sponsor(std::initializer_list<std::string> sponsors);
        void Add_sponsor(std::string sponsor);
        bool operator==(const Team& rhs){return Team_ID() == rhs.Team_ID();}
        bool operator!=(const Team& rhs){return Team_ID() != rhs.Team_ID();}
        //Prints information about the team
        void info(std::ostream &out) const;
        friend std::ostream& operator<<(std::ostream& out, const Team &x);
};
#endif /* Team_hpp */
