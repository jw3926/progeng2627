#include <iostream>

int main(){
    int n, acc = 0;
    while (n != 0){
        std::cout<<"enter a number:"<<std::endl;
        std::cin>>n;
        acc = acc + n;
        std::cout<<"the sum so far is:"<<std::endl;
        std::cout<<acc<<std::endl;
    }
}