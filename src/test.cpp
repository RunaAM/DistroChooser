#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ifstream f("/etc/distrochooserdatabase");
    string s;
    f >> s;
    cout <<s;
    return 0;
}