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
    string release;
    string ootb;
    string desktop_design;
    string desktop_experience;
};


int main(){
    std::cout <<"\033[1;32mbold red text\033[0m\n" <<std::endl;
    user user;
    
    bool loop = true;
    short choice,bufferr;
    const char invalid_message[]="The value you entered is invalid.";
    const char waiting_message[]="Enter a value: ";
    std::cout << "Welcome to distro chooser" << std::endl;
    while(loop){
    
        std::cout << "Do you want to continue with the quiz?\n1.yes\n2.no"<< std::endl;
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
        short user_friendly_buffer,release_buffer,ootb_buffer,desktop_design_buffer,desktop_experience_buffer;
        for(int i = 0;i<8;i++){
            f >> s;
        }
        while(std::getline(f,s)){
            f >> distro.name >> distro.based >> user_friendly_buffer >> release_buffer >> ootb_buffer >> desktop_design_buffer >> desktop_experience_buffer >> distro.desktop;
            distro.user_friendly =(user_friendly_buffer == short_answer::yes) ? "very_user-friendly" : "not_so_user-friendly";
            distro.release = (release_buffer == short_answer::yes) ? "stable_release" : "rolling_release";
            distro.ootb = (ootb_buffer == short_answer::yes) ? "out_of_the_box" : "configure_before_use";
            distro.desktop_design =(desktop_design_buffer == desktop_design::windows) ? "Windows_design" :((desktop_design_buffer == desktop_design::macos) ? "Macos_design" : "Unique_desktop_design");  
            distro.desktop_experience = (desktop_experience_buffer == desktop_experience::fluid) ? "Modern_design" : "Older_design";
            if(user_friendly_buffer == user.beginner_friendly&& release_buffer == user.release && ootb_buffer == user.want_to_configure && desktop_design_buffer == user.desktop_design){
                   
                std::cout<< distro.name <<" "<< distro.based << " "<< distro.user_friendly << " " << distro.release << " " << distro.desktop << std::endl;
            }
        }
    }
    
    return 0;
}