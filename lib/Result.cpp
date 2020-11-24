#include "../include/Result.hpp"
Result::Result(Cyclist* cyclist, int Time_On_Phase, int Additional_Time, int Points): cyclist(cyclist), Time(Time_On_Phase), Additional_Time(Additional_Time), Points(Points){}
void Result::Set_Cyclist(Cyclist* cyc){
    cyclist = cyc;
}
void Result::basic_info(std::ostream &out) const{
    out << "Cyclist ID:" << cyclist->Cyclist_ID()
    << " Time:" << Time
    <<" Additional_Time:" << Additional_Time
    << " Points:" << Points;
}
unsigned int Result::Cyc_Id() const{
    return cyclist->Cyclist_ID();
}
bool Result::operator<(const Result& rhs)const{
    if(cyclist->Cyclist_ID() == rhs.cyclist->Cyclist_ID()){
        return true;
    } else if(Points == rhs.Points){
        return cyclist->Cyclist_ID() < rhs.cyclist->Cyclist_ID();
    } else {
        return Points > rhs.Points;
    }
}
std::ostream& operator<<(std::ostream &out, const Result &x){
    x.basic_info(out);
    return out;
}
