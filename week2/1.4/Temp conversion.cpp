#include <iostream>

int main(){
    double celsius, fahrenheit;
    std::cout << "Degrees celsius?" << std::endl;
    std::cin >> celsius;
    fahrenheit = celsius * 1.8 + 32;
    std::cout << celsius << " degrees celsius is " << fahrenheit << " degrees fahrenheit" << std::endl;   
}