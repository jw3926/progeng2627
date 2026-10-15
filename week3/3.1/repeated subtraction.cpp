#include <iostream>

int main(){
    double x = 0, rem = 0, sub = 0;
        std::cout<<"enter dividend and divider:"<<std::endl;
        std::cin >> rem >> x;
    while (rem > x){
        rem = rem - x;
        sub = sub + 1;
    }
        std::cout<<"quotient is:"<<sub<<std::endl;
        std::cout<<"remainder is:"<<rem<<std::endl;

}