#include <iostream>
#include <string>
#include <fstream>
#include "quiz.h"
using std::string;

struct distro{
    string name;
    string based;
    string desktop;
    string user_friendly;
};


int main(){
    
    user user;
    
    bool loop;
    short choice;
    const char invalid_message[]="The value you entered is invalid.";
    const char waiting_message[]="Enter a value: ";
    std::cout << "Welcome to distro chooser" << std::endl;
    while(loop){
    
        std::cout << "Do you want to continue with the quiz?"<< std::endl;
        std::cout << "1.yes" << std::endl;
        std::cout << "2.no" << std::endl;
        std::cout << waiting_message;
        std::cin >> choice;
        
        if(choice ==2){
            return 0;
        }
        else if(choice !=1){
            std::cout << invalid_message << std::endl;
        }else{
            loop=false;
        }
    }
    quiz(user);
    std::ifstream f{"/etc/distrochooserdatabase"};
    if(f.is_open()){
        string s;
        distro distro;
        short buffer;
        for(int i = 0;i<8;i++){
            f >> s;
        }
        while(std::getline(f,s)){
        f >> distro.name;
        f >> distro.based;
        f >> buffer;
        if(buffer == short_answer::yes){
            distro.user_friendly = "very user-friendly";
        }
        else{
            distro.user_friendly = "not so user-friendly";
        }
        std::cout<< distro.name <<std::endl;
        std::cout<< distro.based <<std::endl;
        std::cout<< distro.user_friendly <<std::endl;
        }
    }
    
    return 0;
}