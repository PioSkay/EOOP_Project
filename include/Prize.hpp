#ifndef Price_hpp
#define Price_hpp

#include "Result.hpp"
#include "Cyclist.hpp"
class Prize: public Result{
    private:
        float Cash;
        void prize_check(const float& prize);
    public:
        Prize(float& Cash, class Cyclist* cyclist);
        Prize(): Result(nullptr), Cash(0){};
        float cash() const;
        void cash_change(const float &cash);
};
#endif /* Price_hpp */
