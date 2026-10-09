#include <iostream>
#include <string>

int main(){

    double t_in, t_out;
    std::string unit_in, unit_out;


    // stage 1: input

    std::cin >> t_in >> unit_in;

    bool valid_unit = true;
    // we assume the user will input a valid unit

    // stage 2: data processing

    if(unit_in == "f" || unit_in == "F"){
        unit_out = "C";
        t_out = (t_in - 32) *5 / 9;

    }
    else if(unit_in == "c" || unit_in == "C"){
        unit_out = "f";
        t_out = t_in * 1.8 + 32;
    }
    else{
        valid_unit = false;
        // if the user inputs an invalid unit name
        // we update this variable
    }

    // stage 3: output 

    if(valid_unit){
        std::cout << t_out << " " << unit_out << std::endl;
    }
    else{
        std::cout << "error, unit not recognised" << std::endl;
    }

}