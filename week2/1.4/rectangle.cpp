#include <iostream>

int main(){
    double length, width, perimeter, area;
    std::cout << "Length?" << std::endl;
    std::cin >> length;
    std::cout << "Width?" << std::endl;
    std::cin >> width;
    perimeter = length * 2 + width * 2;
    area = length * width;
    std::cout << "Perimeter: " << perimeter << " Area: " << area <<std::endl;   
}