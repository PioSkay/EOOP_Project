#include "../include/Prize.hpp"
void Prize::prize_check(const float& prize){
    if(prize <= 0){
        throw std::invalid_argument("Prize: Prize can not be lower than 0!");
    }
}
Prize::Prize(float& Cash, class Cyclist* cyclist): Result(cyclist){
    prize_check(Cash);
    Prize::Cash = Cash;
}
float Prize::cash() const{
    return Cash;
}
void Prize::cash_change(const float &cash){
    prize_check(cash);
    Cash = cash;
}
