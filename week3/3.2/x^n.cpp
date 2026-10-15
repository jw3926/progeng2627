#include <iostream>

int main(){
    int x, n, acc = 1;
    std::cout << "x and n?" << std::endl;
    std::cin>>x>>n;
    for(int i = 0; i < n; i++){
        acc = acc * x;
    }
    std::cout << acc<< std::endl;
}
