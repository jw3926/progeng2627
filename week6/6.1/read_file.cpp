#include <iostream>
#include <fstream>

int main(){
    std::string a;

    std::cin>>a;

    std::fstream infile;
    infile.open(a);

    int tmp;
    int sum = 0;
    if (infile.is_open()){
    while (infile>>tmp){
        sum = sum + tmp;
    }}else{
        return EXIT_FAILURE;
    }
    std::cout<<sum<<std::endl;
    infile.close();
}