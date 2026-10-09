#include <iostream>

int main(){
    double pounds, euros, xrate;
    xrate = 1.18;
    std::cout << "Pounds?" << std::endl;
    std::cin >> pounds;
    euros = xrate * pounds;
    std::cout << pounds << " pounds is " << euros << " euros" << std::endl;   
}