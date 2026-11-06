#include <iostream>
#include <fstream>
#include <vector>

int main(){
    std::string a;
    std::fstream infile;
    std::vector<std::string> string_vector;

    infile.open("input.txt");

    if (!infile.is_open()){
        std::cout<<"File not found!"<<std::endl;
        return EXIT_FAILURE;
    }

    while (infile>>a){
        string_vector.push_back(a);
    }

    for (int i=string_vector.size(); i>0; i--){
        std::cout<<string_vector[i-1];
    }
}