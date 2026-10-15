#include <iostream>
#include <string>

int main(){
    std::string n = "";

    while(n != "STOP" && n != "Stop" && n != "stop"){ // != means different or not equal
        std::cin >> n;
        std::cout << n << std::endl;
    }
}