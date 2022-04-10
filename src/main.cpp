#include <iostream>
#include <string>
#include "quiz.h"
using std::string;
struct distro{
    string name;
    string based;
    string desktop;
    string personalized;
    string user_friendly;
};


int main(){
    /*ifstream f;
    f.open("distrodatabase.txt",ios::in);
    if(f.is_open()){
        string s;
        distro distro;
        getline(f,s);
        while(getline(f,s)){
            distro.name = s.substr(0,s.find(' '));
            distro.based = s.substr(1,s.find(' '));
            distro.desktop = s.substr(2,s.find(' '));
            distro.personalized = s.substr(3,s.find(' '));
            distro.user_friendly = s.substr(4,s.find(' '));
            cout << distro.based << endl;
        }
    }
    */
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
    return 0;
}