#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void union_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout);

void intersection_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout);

bool search_vector(std::string s, const std::vector<std::string>& vin);

void read_file(std::ifstream& infile, std::vector<std::string>& vin);

void write_file(std::ofstream& infile, std::vector<std::string>& vin);

int main() {
    std::string in1;
    std::string in2;


    std::cout<<"In 1?"<<std::endl;
    std::cin>>in1;
    std::cout<<"In 2?"<<std::endl;
    std::cin>>in2;

    std::ifstream infile1;
    std::ifstream infile2;
    std::ofstream outfile1;
    std::ofstream outfile2;

    infile1.open(in1);
    infile2.open(in2);
    outfile1.open("union.txt");
    outfile2.open("intersection.txt");

    std::vector<std::string> vin1;
    std::vector<std::string> vin2;
    std::vector<std::string> vout;

    
    if (!infile1.is_open() || !infile2.is_open() || !outfile1.is_open() || !outfile2.is_open()){
        std::cout<<"ERROR!"<<std::endl;
        return EXIT_FAILURE;
    }

    read_file(infile1, vin1);
    read_file(infile2, vin2);

    union_vector(vin1, vin2, vout);
    write_file(outfile1, vout);
    vout.clear();
    intersection_vector(vin1, vin2, vout);
    write_file(outfile2, vout);
    return 0;
}


void read_file(std::ifstream& infile, std::vector<std::string>& vin){
    std::string tmp;
    while (infile>>tmp){
        vin.push_back(tmp);
    }
}

void write_file(std::ofstream& outfile, std::vector<std::string>& vin){
    for (int i = 0; i < vin.size(); i++){
        outfile<<vin.at(i)<<std::endl;
    }
}

void union_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    for (int i = 0; i < vin1.size(); i++)
    {
        if (!search_vector(vin1.at(i), vout)){
            vout.push_back(vin1.at(i));
        }
    }
        for (int i = 0; i < vin2.size(); i++)
    {
        if (!search_vector(vin2.at(i), vout)){
            vout.push_back(vin2.at(i));
        }
    }
}

void intersection_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    for (int i = 0; i < vin1.size(); i++)
    {
        if (search_vector(vin1.at(i), vin2)){
            vout.push_back(vin1.at(i));
        }
    }
}

bool search_vector(std::string s, const std::vector<std::string>& vin){
    for (int i = 0; i < vin.size(); i++)
        if (vin.at(i)==s){
            return true;
        }
    return false;
    }

