#include "../include/test.hpp"
int Test::file_loc(std::string& loc){
    int missing_files = 0;
    for(int i = 1; i <= 6; i++){
        if(is_file_there(loc + "/Tournament/"+ std::to_string(i) +"/config.txt") == false){
            missing_files++;
        }
    }
    for(int i = 12; i <= 15; i++){
        if(is_file_there(loc + "/Tournament/"+ std::to_string(i) +"/config.txt") == false){
            missing_files++;
        }
    }
    for(int i = 1; i <= 6; i++){
        if(is_file_there(loc + "/Tournament/17/results" + std::to_string(i) + ".txt") == false){
            missing_files++;
        }
    }
    if(is_file_there(loc + "/Tournament/7/config.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/7/teams.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/8/config.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/8/teams.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/8/cyclist.txt") == false){
        missing_files++;
    }
    for(int i = 9; i <= 11; i++){
        if(is_file_there(loc + "/Tournament/"+ std::to_string(i) +"/config.txt") == false){
            missing_files++;
        }
        if(is_file_there(loc + "/Tournament/"+ std::to_string(i) +"/teams.txt") == false){
            missing_files++;
        }
        if(is_file_there(loc + "/Tournament/"+ std::to_string(i) +"/cyclist.txt") == false){
            missing_files++;
        }
        if(is_file_there(loc + "/Tournament/"+ std::to_string(i) +"/phase.txt") == false){
            missing_files++;
        }
    }
    if(is_file_there(loc + "/Tournament/16/config.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/16/teams.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/16/phase.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/16/cyclist.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/16/results.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/16/gen.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/16/a.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/16/b.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/16/c.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/18/config.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/18/teams.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/18/phase.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/18/cyclist.txt") == false){
        missing_files++;
    }
    if(is_file_there(loc + "/Tournament/18/gen.txt") == false){
        missing_files++;
    }
    return missing_files;
}
bool Test::is_file_there(const std::string& loc){
    return (access(loc.c_str(), F_OK) != -1);
}
void Test::Tournament_Check(){
    try{
        Tournament x(loc + "/Tournament/0/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Config file not found!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/1/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: cyclist/phase/general path not found!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/2/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Incorrect teams file name!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/3/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Incorrect results file name!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/4/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Incorrect general file name!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/5/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Incorrect phase file name!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/6/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Team file not found!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/7/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Cyclist file not found!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/8/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Phase file not found!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/9/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: General file not found!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/10/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Incorrect general file name!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/11/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Incorrect general file name!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/12/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Teams path already exists!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/13/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Phase path already exists!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/14/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: General path already exists!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/15/");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Cyclist path already exists!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/16/");
        x.add_general_info("");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Name not found!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/16/");
        x.add_general_info("Name:");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Name content not found!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/16/");
        x.add_general_info("Name:Name;");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Blue not found!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/16/");
        x.add_general_info("Name:Name;Blue:");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Blue content not found!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/16/");
        x.add_general_info("Name:Name;Blue:---;");
    }catch(std::exception &a){
        Errors.push_back(Error("stof: no conversion",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/16/");
        x.add_general_info("Name:Name;Blue:12;");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Green not found!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/16/");
        x.add_general_info("Name:Name;Blue:12;Green:");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Green content not found!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/16/");
        x.add_general_info("Name:Name;Blue:12;Green:---;");
    }catch(std::exception &a){
        Errors.push_back(Error("stof: no conversion",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/16/");
        x.add_general_info("Name:Name;Blue:12;Green:13;");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Red not found!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/16/");
        x.add_general_info("Name:Name;Blue:12;Green:13;Red:");
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Red content not found!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/16/");
        x.add_general_info("Name:Name;Blue:12;Green:13;Red:---;");
    }catch(std::exception &a){
        Errors.push_back(Error("stof: no conversion",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/16/");
        x.add_cyclist(Cyclist("ID:12;Age:12;Name:Name;Surname:Surname;Nation:PL;", nullptr));
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Registration is over! Can not add new phase/cyclist!",a.what()));
    }
    try{
        Tournament x(loc + "/Tournament/18/");
        x.add_cyclist(Cyclist("ID:12;Age:12;Name:Name;Surname:Surname;Nation:PL;", nullptr));
        x.add_cyclist(Cyclist("ID:12;Age:12;Name:Name;Surname:Surname;Nation:PL;", nullptr));
    }catch(std::exception &a){
        Errors.push_back(Error("Tournament: Cyclist not unique!",a.what()));
    }
}
void Test::Cyclist_Check(){
    try{
        Cyclist x("", nullptr);
    }catch(std::exception &a){
        Errors.push_back(Error("Cyclist: ID not found!",a.what()));
    }
    try{
        Cyclist x("ID:", nullptr);
    }catch(std::exception &a){
        Errors.push_back(Error("Cyclist: ID content not found!",a.what()));
    }
    try{
        Cyclist x("ID:---;", nullptr);
    }catch(std::exception &a){
        Errors.push_back(Error("stoi: no conversion",a.what()));
    }
    try{
        Cyclist x("ID:12;", nullptr);
    }catch(std::exception &a){
        Errors.push_back(Error("Cyclist: Age not found!",a.what()));
    }
    try{
        Cyclist x("ID:12;Age:", nullptr);
    }catch(std::exception &a){
        Errors.push_back(Error("Cyclist: Age content not found!",a.what()));
    }
    try{
        Cyclist x("ID:12;Age:-10;", nullptr);
    }catch(std::exception &a){
        Errors.push_back(Error("Cyclist: Wrong age!",a.what()));
    }
    try{
        Cyclist x("ID:12;Age:---;", nullptr);
    }catch(std::exception &a){
        Errors.push_back(Error("stoi: no conversion",a.what()));
    }
    try{
        Cyclist x("ID:12;Age:12;", nullptr);
    }catch(std::exception &a){
        Errors.push_back(Error("Cyclist: Name not found!",a.what()));
    }
    try{
        Cyclist x("ID:12;Age:12;First_Name:", nullptr);
    }catch(std::exception &a){
        Errors.push_back(Error("Cyclist: Name content not found!",a.what()));
    }
    try{
        Cyclist x("ID:12;Age:12;First_Name:Name;", nullptr);
    }catch(std::exception &a){
        Errors.push_back(Error("Cyclist: Surname not found!",a.what()));
    }
    try{
        Cyclist x("ID:12;Age:12;Name:Name;Surname:", nullptr);
    }catch(std::exception &a){
        Errors.push_back(Error("Cyclist: Surname content not found!",a.what()));
    }
    try{
        Cyclist x("ID:12;Age:12;Name:Name;Surname:Surname;", nullptr);
    }catch(std::exception &a){
        Errors.push_back(Error("Cyclist: Nation not found!",a.what()));
    }
    try{
        Cyclist x("ID:12;Age:12;Name:Name;Surname:Surname;Nation:", nullptr);
    }catch(std::exception &a){
        Errors.push_back(Error("Cyclist: Nation content not found!",a.what()));
    }
}
void Test::Phase_Check(){
    try{
        std::list<Cyclist> a;
        Phase x("", a);
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: ID not found!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        Phase x("ID:", a);
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: ID content not found!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        Phase x("ID:---;", a);
    }catch(std::exception &a){
        Errors.push_back(Error("stoi: no conversion",a.what()));
    }
    try{
        std::list<Cyclist> a;
        Phase x("ID:12;", a);
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: Distance not found!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        Phase x("ID:12;Distance:", a);
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: Distance content not found!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        Phase x("ID:12;Distance:---;", a);
    }catch(std::exception &a){
        Errors.push_back(Error("stof: no conversion",a.what()));
    }
    try{
        std::list<Cyclist> a;
        Phase x("ID:12;Distance:128;", a);
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: Course not found!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        Phase x("ID:12;Distance:128;Course:", a);
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: Course content not found!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        Phase x("ID:12;Distance:128;Course:Poland-Poland;", a);
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: Type not found!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        Phase x("ID:12;Distance:128;Course:Poland-Poland;Type:", a);
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: Type content not found!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        Phase x("ID:12;Distance:128;Course:Poland-Poland;Type:M;", a);
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: Wrong Type!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        a.push_back(Cyclist("ID:12;Age:12;Name:Name;Surname:Surname;Nation:PL;", nullptr));
        Phase x("ID:12;Distance:128;Course:Poland-Poland;Type:Mountain Stage;", a);
        x.Enter_Results(11, 10, 10);
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: Wrong ID in results!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        a.push_back(Cyclist("ID:12;Age:12;Name:Name;Surname:Surname;Nation:PL;", nullptr));
        Phase x("ID:12;Distance:128;Course:Poland-Poland;Type:Mountain Stage;", a);
        x.Enter_Results(12, 10, 10);
        x.Finish_Registration(a);
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: Results already filled!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        a.push_back(Cyclist("ID:12;Age:12;Name:Name;Surname:Surname;Nation:PL;", nullptr));
        Phase x("ID:12;Distance:128;Course:Poland-Poland;Type:Mountain Stage;", a);
        x.lock();
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: Phase can not be locked!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        a.push_back(Cyclist("ID:12;Age:12;Name:Name;Surname:Surname;Nation:PL;", nullptr));
        Phase x("ID:12;Distance:128;Course:Poland-Poland;Type:Mountain Stage;", a);
        x.player_points(11);
    }catch(std::exception &a){
        Errors.push_back(Error("Phase/player_points: Player's ID not found!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        a.push_back(Cyclist("ID:12;Age:12;Name:Name;Surname:Surname;Nation:PL;", nullptr));
        Phase x("ID:12;Distance:128;Course:Poland-Poland;Type:Mountain Stage;", a);
        x.Enter_Results(loc + "/Tournament/0/results.txt");
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: Results file not found!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        a.push_back(Cyclist("ID:12;Age:12;Name:Name;Surname:Surname;Nation:PL;", nullptr));
        Phase x("ID:12;Distance:128;Course:Poland-Poland;Type:Mountain Stage;", a);
        x.Enter_Results(loc + "/Tournament/17/results1.txt");
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: Wrong ID in results!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        a.push_back(Cyclist("ID:12;Age:12;Name:Name;Surname:Surname;Nation:PL;", nullptr));
        Phase x("ID:12;Distance:128;Course:Poland-Poland;Type:Mountain Stage;", a);
        x.Enter_Results(loc + "/Tournament/17/results2.txt");
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: ID not found!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        a.push_back(Cyclist("ID:12;Age:12;Name:Name;Surname:Surname;Nation:PL;", nullptr));
        Phase x("ID:12;Distance:128;Course:Poland-Poland;Type:Mountain Stage;", a);
        x.Enter_Results(loc + "/Tournament/17/results3.txt");
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: ID content not found!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        a.push_back(Cyclist("ID:12;Age:12;Name:Name;Surname:Surname;Nation:PL;", nullptr));
        Phase x("ID:12;Distance:128;Course:Poland-Poland;Type:Mountain Stage;", a);
        x.Enter_Results(loc + "/Tournament/17/results4.txt");
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: Time not found!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        a.push_back(Cyclist("ID:12;Age:12;Name:Name;Surname:Surname;Nation:PL;", nullptr));
        Phase x("ID:12;Distance:128;Course:Poland-Poland;Type:Mountain Stage;", a);
        x.Enter_Results(loc + "/Tournament/17/results5.txt");
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: Time content not found!",a.what()));
    }
    try{
        std::list<Cyclist> a;
        a.push_back(Cyclist("ID:12;Age:12;Name:Name;Surname:Surname;Nation:PL;", nullptr));
        Phase x("ID:12;Distance:128;Course:Poland-Poland;Type:Mountain Stage;", a);
        x.Enter_Results(loc + "/Tournament/17/results6.txt");
    }catch(std::exception &a){
        Errors.push_back(Error("Phase: Wrong Cyclist Additional_Time!",a.what()));
    }
}
void Test::Team_Test(){
    try{
        Team x("");
    }catch(std::exception &a){
        Errors.push_back(Error("Team: Name not found!",a.what()));
    }
    try{
        Team x("Sponsors:");
    }catch(std::exception &a){
        Errors.push_back(Error("Team: Wrong sponsors list!",a.what()));
    }
    try{
        Team x("Name:");
    }catch(std::exception &a){
        Errors.push_back(Error("Team: Wrong Name!",a.what()));
    }
    try{
        Team x("Name:Name;");
    }catch(std::exception &a){
        Errors.push_back(Error("Team: ID not found!",a.what()));
    }
    try{
        Team x("Name:Name;ID:");
    }catch(std::exception &a){
        Errors.push_back(Error("Team: Wrong ID!",a.what()));
    }
    try{
        Team x("Name:Name;ID:---;");
    }catch(std::exception &a){
        Errors.push_back(Error("stoi: no conversion",a.what()));
    }
    try{
        Team x("Name:Name;ID:12;");
    }catch(std::exception &a){
        Errors.push_back(Error("Team: Short_Name not found!",a.what()));
    }
    try{
        Team x("Name:Name;ID:12;Short_Name:");
    }catch(std::exception &a){
        Errors.push_back(Error("Team: Wrong Short_Name!",a.what()));
    }
}
void Test::Full_Report(){
    Tournament_Check();
    Cyclist_Check();
    Phase_Check();
    Team_Test();
    info(std::cout);
    corr_info(std::cout);
}
