#ifndef Tournament_hpp
#define Tournament_hpp

#include <list>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Cyclist.hpp"
#include "Phase.hpp"
#include "Prize.hpp"
#include "Team.hpp"
#include "Result.hpp"
enum What{GENERAL = 0, PHASE = 1, CYCLIST = 2, TEAM = 3};
enum Oper{O_NONE, LOWER, GRATER, EQUAL, GRATER_EQUAL, LOWER_EQUAL};
enum Operations{OP_NONE, ID, AGE, FIRSTNAME, LASTNAME, NATION, TEAM_ID, TEAM_NAME, TEAM_SHORT_NAME, PHASE_TYPE, PHASE_ID_ADVANCED, PHASE_STATUS};
enum Stage_Of_Tournament{Registration, In_progress, Tournament_Done};
class Tournament{
    private:
        const std::vector<std::string> What_Text = {"General", "Phase", "Cyclist", "Team", "Results"};
        const std::vector<std::string> Type_As_String = {"Mountain_Stage", "Hilly_Stage", "Individual_Time_Trial", "Flat_Stage"};
        const std::vector<std::string> Status_As_String = {"Undone", "Done", "Locked"};
        std::string Name;
        //list of the memebers
        std::list<Cyclist> Cyclists;
        //list of the phases
        std::list<Phase> Phases;
        //list of the teams
        std::list<Team> Teams;
        Stage_Of_Tournament Stage;
        //generalt winner from points classification
        Prize Winner_Green;
        //winner of time classification
        Prize Winner_Red;
        //winner of the mountain calssification
        Prize Winner_Blue;
        //checking if the name is correct
        bool is_name_correct(std::string& text);
        Team* find_team(const unsigned int ID);
        bool Team_Unique(const unsigned int ID) const;
        bool Cyclist_Unique(const unsigned int ID) const;
        bool Phase_Unique(const unsigned int ID) const;
        bool Can_Be_Filled(const unsigned int ID) const;
        std::list<Result> Calc_Based_On_Type(Type type);
        void final_calc();
        void Reg_Check();
        void add_gerneral_info_file(const std::string& line);
        void add_cyclist(const std::string& line);
        void add_team(const std::string& line);
        void add_phase(const std::string& line);
        std::string construct_data(const std::string& text, const std::string& data);
        void is_ok_line(std::string& target, std::string& line, std::string msg);
        struct Files_Loc{
            std::string teams_loc, cyclist_loc, phase_loc, results_loc, general_loc;
        };
        //Search functions
        template <typename Class, typename Var>
        void operations(std::ostream& out, std::list<Class>& list, const Var& a, Var (Class::*f)() const, const enum Oper& op, const bool& access, void (Class::*data)(std::ostream& out) const);
        int converter(const std::vector<std::string>& elements, const std::string& text) const;
        template<class Iter, class Function, class Class>
        void output(std::ostream& out, Iter begin, Iter end, Function fun, void (Class::*data)(std::ostream& out) const);
        void data_proceed(std::ostream& out, const enum What& w, const enum Operations& o, const enum Oper& op, const std::string& arg);
    public:
        Tournament(const std::list<Cyclist>& Cyclists, const std::list<Phase>& Phases);
        Tournament(const std::string& loc);
        ~Tournament();
        void add(const enum What& what, void (Tournament::*f)(const std::string& line), Tournament& x, const std::string& path);
        void add_general_info(const std::string& text);
        void add_cyclist(const Cyclist& cyclist);
        void add_team(const Team& team);
        void add_results(const std::string& loc, const std::string& name);
        void calculate();
        void lock_phases();
        //Showing info
        void Show(const enum What& w, const enum Operations& o = OP_NONE, const enum Oper& op = O_NONE, const std::string& arg = "");
        //Saving info
        void Save(const std::string& path, const enum What& w, const enum Operations& o = OP_NONE, const enum Oper& op = O_NONE, const std::string& arg = "");
        //info
        void info(std::ostream& out) const;
        friend std::ostream& operator<<(std::ostream& out, const Tournament& x);
};
#endif /* Tournament_hpp */
