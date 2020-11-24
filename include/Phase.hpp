#ifndef phase_hpp
#define phase_hpp
#include <string>
#include <fstream>
#include "Cyclist.hpp"
#include <set>
#include "Result.hpp"
enum Type{Mountain_Stage = 0, Hilly_Stage = 1, Individual_Time_Trial = 2, Flat_Stage = 3};
enum Status{Undone, Done, Locked};
//*Phase is defined by the Status. It could be undone-it means that it is not done yet, results are not filled yet, there is no winner and leader but all of the players are loaded. done-phase is done. there are all results and winner plus leader. Locked-when the phase is compleated all resultes are filled there is winned and leader and u are ready to start the next phase.Start = To change the status of the next phase to Done or Locked. Warning! U wont be able to change anything inside the phase when its Locked!
class Phase{
    private:
        unsigned int stage_ID;
        std::string Course;
        float distance;
        Type type;
        //status of the phase *done/undone
        Status status;
        //Winner and leader
        Cyclist* Winner;
        Cyclist* Leader;
        //results of the player on current phase
        std::set<Result> Results;
        void Is_Phase_Done();
        std::string construct_data(const std::string& text, const std::string& data);
    public:
        Phase(unsigned int stage_ID, std::string& Course, float distance, enum Type Type, std::list<Cyclist>& cyclists);
        Phase(const std::string& text, std::list<Cyclist>& cyclists);
        ~Phase(){};
        std::string course()const{return Course;}
        unsigned int phase_ID() const{return stage_ID;};
        //only players with payed bills will be signed up
        void Finish_Registration(std::list<Cyclist>& cyclists);
        //u can enter data via three ways
        void Enter_Results(const unsigned int id, const int Time, const int Additional_Time);
        void Enter_Results(const unsigned int id, int const Time);
        void Enter_Results(const std::string loc);
        void Set_Led(Cyclist* Leader);
        std::set<Result> Results_Data() {return Results;}
        Cyclist* Winner_Data(){return Winner;}
        Cyclist* Leader_Data(){return Leader;}
        //locking the class will finally end the phase.
        void lock();
        bool is_done() const;
        bool is_locked() const;
        Type Phase_Type() const {return type;};
        Status Phase_Status() const {return status;};
        //info
        int player_points(const unsigned int ID);
        void info_basic(std::ostream &out) const;
        void info_advanced(std::ostream &out) const;
        bool operator==(const Phase& rhs)const{return stage_ID == rhs.stage_ID;};
        bool operator!=(const Phase& rhs)const{return stage_ID != rhs.stage_ID;};
        friend std::ostream& operator<<(std::ostream &out, const Phase &x);
};
#endif /* phase_hpp */
