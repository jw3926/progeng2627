#include <iostream>

int main(){
    double n, counter = 1, acc = 0, avg = 0;
    while (n != 0){
        std::cout<<"enter a number:"<<std::endl;
        std::cin>>n;
        acc = acc + n;
        avg = acc / counter;
        std::cout<<"the average so far is:"<<std::endl;
        std::cout<<avg<<std::endl;
        counter = counter + 1;
    }
}