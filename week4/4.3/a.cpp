#include <iostream>
int a (const int& a, int b){
    a = 3;
    return a+b;
    
}


int main(){
    std::cout<<a(1,2)<<std::endl;
}

