#include <iostream>
#include <iomanip>

int main(){
    double height, weight, BMI;
    std::cout << "Height (m)?" << std::endl;
    std::cin >> height;
    std::cout << "Weight (kg)?" << std::endl;
    std::cin >> weight;
    BMI = weight / (height * height);
    std::cout << "BMI: " << std::fixed << std::setprecision(1) << BMI << std::endl;   
}