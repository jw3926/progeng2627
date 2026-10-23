#include <iostream>

double mypow(double base, int exp){
    double result; 
    result = 1;
    if (exp > 0){
    for (int i = 0; i < exp; i++){
        result = result * base;
    }
    }else{
    for (int i = 0; i < - exp; i++){
        result = result * base;
    }
    result = 1 / result;
    }
    return result;
}

int main(){
    
    std::cout << "2^3: " << mypow(2, 3) << std::endl;
    std::cout << "0.5^2: " << mypow(0.5, 2) << std::endl;
    std::cout << "1^0: " << mypow(1, 0) << std::endl;
}