#ifndef Result_hpp
#define Result_hpp

#include <compare>
#include "Cyclist.hpp"
//results of the player in the specific run
class Result{
    private:
        Cyclist* cyclist;
        unsigned int Time;
        int Additional_Time;
        int Points;
    public:
        Result(Cyclist* cyclist): cyclist(cyclist), Time(0), Additional_Time(0), Points(-1){};
        Result(Cyclist* cyclist, int Time_On_Phase, int Additional_Time, int Points);
        ~Result(){}
        void Set_Cyclist(Cyclist* cyc);
        Cyclist* Cyclist_Data()const{return cyclist;} 
        unsigned int Cyc_Id() const;
        int Points_Data()const{return Points;}
        void Points_Change(int points){Points = points;}
        bool operator<(const Result& rhs)const;
        Result& operator=(const Result& rhs);
        void basic_info(std::ostream &out) const;
        friend std::ostream& operator<<(std::ostream &out, const Result &x);
};
#endif /* Result_hpp */
