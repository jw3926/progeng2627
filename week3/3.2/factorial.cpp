#include <iostream>

int main(){
    double x, n, acc = 1;
    std::cout << "x?" << std::endl;
    std::cin>>x;
    if (x > 0){
    while(x > 0){
        acc = acc * x;
        x -= 1;
    }
    std::cout << acc << std::endl;
    }else if (x == 0){
    std::cout << acc << std::endl;
    }else{
    std::cout << "invalid" << std::endl;
    }
}
