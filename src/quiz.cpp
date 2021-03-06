#include "quiz.h"
#include <iostream>
void quiz(user &user){
    unsigned short choice;
    bool loop = true;
    const char invalid_message[]="The value you entered is invalid.";
    const char waiting_message[]="Enter a value: ";
    
    
    loop = true;
    while(loop){
        std::cout << "I.What do you think about beginner friendly ?\n1.I really want to be beginner friendly.\n2.I dont really care if it is beginner friendly.\n3.I dont want to be beginner friendly."<< std::endl;
        std::cout << waiting_message;
        std::cin >> choice;
        if(choice >0 && choice <4){
            loop = false;
        }
        else{
            std::cout << invalid_message <<std::endl;
        }
    }
    user.beginner_friendly = choice;
    loop = true;
    while(loop){
        std::cout <<"II.Do you want your distro to be out of the box?\n1.Yes, i want to install it and just get to work.\n2.No, I want to configure first before using it" << std::endl;
        std::cout << waiting_message;
        std::cin >> choice;
        if(choice !=1 && choice !=2){
            std::cout << invalid_message<<std::endl;
        }
        else{
            loop=false;
            user.want_to_configure = (bool)(choice -1);
        }
    }
    loop = true;
    while(loop){
        std::cout <<"III.What kind of updates do you want?\n1.Stable release (when an os upgrade is available you must reinstall the os)\n2.Rolling release (frequently updates that dont require a reinstall)" << std::endl;
        std::cout << waiting_message;
        std::cin >> choice;
        if(choice !=1 && choice !=2){
            std::cout << invalid_message << std::endl;
        }
        else{
            user.release = choice;
            loop = false;
        }
    }
    loop = true;
    while(loop){
        std::cout << "IV.What desktop experiece are you expecting from your distro?\n1.A fluid one with animations and unique features\n2.A very snappy one with windows 7 like theme and no animations"<<std::endl;
        std::cout << waiting_message;
        std::cin >> choice;
        if(choice !=1 && choice !=2){
            std::cout << invalid_message << std::endl;
            
        }
        else{
            user.desktop_experience = choice;
            loop = false;
        }
        
    }
    loop = true;
    while(loop){
        std::cout << "V.What design your desktop should have?\n1.A windows like design.\n2.A macos like design.\n3.I don\'t really care" << std::endl;
        std::cout << waiting_message;
        std::cin >> choice;
        if(choice >0 && choice <4){
            user.desktop_design = choice;
            loop = false;
        }
        else{
            std::cout << invalid_message <<std::endl;
        }
    }
}