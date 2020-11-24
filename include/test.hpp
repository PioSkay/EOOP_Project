#ifndef test_hpp
#define test_hpp

#include<iostream>
#include<list>
#include<string>
#include<unistd.h>
#include"Tournament.hpp"

class Error{
    private:
        std::string expected;
        std::string actual;
        bool correct;
    public:
        Error(std::string expected, std::string actual): expected(expected), actual(actual){
            correct = (expected == actual);
        };
        bool Is_Correct() const{return correct;}
        Error(){expected.clear(); actual.clear();}
        friend std::ostream& operator<<(std::ostream& out, const Error x){
            out << "Error: "<<x.actual<<std::endl<<"Expected Error: "<<x.expected<<std::endl;
            if(x.correct == true){
                out << "Correct test!"<<std::endl;
            } else {
                out << "Incorrect test!"<<std::endl;
            }
            return out;
        }
};
class Test{
    private:
        std::list<Error> Errors;
        std::string loc;
        int file_loc(std::string& loc);
        bool is_file_there(const std::string& loc);
    public:
        Test(std::string loc){
            Test::loc = loc;
            int missing_files = file_loc(loc);
            if(missing_files != 0){
                if(missing_files == 1){
                    throw std::invalid_argument("Could not find " + std::to_string(missing_files) + " file.");
                } else {
                    throw std::invalid_argument("Could not find " + std::to_string(missing_files) + " files.");
                }
            }
        };
        ~Test(){Errors.clear();};
        //Tests
        void Tournament_Check();
        void Cyclist_Check();
        void Phase_Check();
        void Team_Test();
        void Full_Report();
    
        void corr_info(std::ostream& out) const{
            int number_of_test = 0, correct_tests = 0;
            for(std::list<Error>::const_iterator it = Errors.begin(); it != Errors.end(); it++){
                if(it->Is_Correct() == true){
                    correct_tests++;
                }
                number_of_test++;
            }
            if(number_of_test == correct_tests){
                out << "All "<<number_of_test<<" tests are correct!" <<std::endl;
            } else {
                out << "Correct tests: "<<correct_tests<<", Number of tests: "<<number_of_test<<std::endl;
            }
        }
        void info(std::ostream& out) const{
            for(std::list<Error>::const_iterator it = Errors.begin(); it != Errors.end(); it++){
                out << *it << std::endl;
            }
        }
        friend std::ostream& operator<<(std::ostream& out, const Test& x){
            x.info(out);
            x.corr_info(out);
            return out;
        }
};
#endif /* test_hpp */
