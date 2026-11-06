#include <iostream>
#include <fstream>
#include <vector>
#include <string>


void read_file(std::ifstream& infile, std::vector<std::string>& vin);

void write_file(std::ofstream& outfile, std::vector<std::string>& vinword, std::vector<int>& vinnum);

int main(){
    std::ifstream infile1;
    std::ifstream infile2;
    std::ofstream outfile;

    infile1.open("text.txt");
    infile2.open("word.txt");
    outfile.open("result.txt");

    std::vector<std::string> vin1;
    std::vector<std::string> vin2;
    std::vector<std::string> voutword;
    std::vector<int> voutnum;

    read_file(infile1, vin1);
    read_file(infile2, vin2);

    if (!infile1.is_open() || !infile2.is_open() || !outfile.is_open()){
        std::cout<<"ERROR!"<<std::endl;
        return EXIT_FAILURE;
    }

    int num;
    for (int i = 0; i < vin2.size(); i++){
        num = 0;
        for (int a = 0; a < vin1.size(); a++){
            if (vin2.at(i) == vin1.at(a)){
                num ++;
                if (num == 1){
                    voutword.push_back(vin2.at(i));
                }
            }
        }
        voutnum.push_back(num);
    }
    write_file(outfile, voutword, voutnum);




}

void read_file(std::ifstream& infile, std::vector<std::string>& vin){
    std::string tmp;
    while (infile>>tmp){
        vin.push_back(tmp);
    }
}

void write_file(std::ofstream& outfile, std::vector<std::string>& vinword, std::vector<int>& vinnum){
    for (int i = 0; i < vinword.size(); i++){
        outfile<<vinword.at(i)<<": "<<vinnum.at(i)<<std::endl;
    }
}