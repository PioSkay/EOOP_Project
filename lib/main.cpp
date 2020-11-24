#include "../include/Tournament.hpp"
#include "../include/test.hpp"
void example()
{
    std::string loc;
    std::cout<<"Please enter example folder loc (it needs to end with /)"<<std::endl;
    std::cin>>loc;
    Tournament x(loc);
    std::cout<<"Cyclists with age lower equal than 19(press enter)"<<std::endl;
    getchar();
    x.Show(CYCLIST, AGE, LOWER_EQUAL, "19");
    std::cout<<"General info(press enter)"<<std::endl;
    getchar();
    x.Show(GENERAL);
    std::cout<<"General info after lock_phases(press enter)"<<std::endl;
    x.lock_phases();
    getchar();
    x.Show(GENERAL);
    std::cout<<"Cyclist from team with id 12 (text will include team info)(press enter)"<<std::endl;
    getchar();
    x.Show(CYCLIST, TEAM_ID, EQUAL, "12");
    std::cout<<"Phases with type Hilly_Stage(press enter)"<<std::endl;
    getchar();
    x.Show(PHASE, PHASE_TYPE, EQUAL, "Hilly_Stage");
}
int main() {
    std::string loc;
    std::cout<<"Please enter tests folder loc (it needs to end with /)"<<std::endl;
    std::cin>>loc;
    Test Tests(loc);
    Tests.Full_Report();
    example();
}
