#include <iostream>

// we can define a function that returns a bool

bool leap_year(int year){
    bool ly = false;

    if (year % 4 == 0 && year % 100 != 0){
        ly = true;
    }

    if (year % 400 == 0){
        ly = true;
    }

    return ly;
    // we *do not print* anything in the function
}

int main(){

    int input_year;


    std::cout << (leap_year(1600) == true) << std::endl;
    std::cout << (leap_year(1700) == false) << std::endl;
    std::cout << (leap_year(1800) == false) << std::endl;
    std::cout << (leap_year(1900) == false) << std::endl;
    std::cout << (leap_year(2000) == true) << std::endl;
    std::cout << (leap_year(2100) == false) << std::endl;
    std::cout << (leap_year(2300) == false) << std::endl;
    std::cout << (leap_year(2500) == false) << std::endl;
    std::cout << (leap_year(2600) == false) << std::endl;
    std::cout << (leap_year(2700) == false) << std::endl;
    std::cout << (leap_year(2900) == false) << std::endl;
    std::cout << (leap_year(3000) == false) << std::endl;

    std::cout << "please enter a year" << std::endl;
    std::cin >> input_year;

    if(leap_year(input_year)){
        std::cout << "it's a leap year" << std::endl;
    }
    else{
        std::cout << "it's not a leap year" << std::endl;
    }

}