#include <vector>
#include <iostream>
#include <fstream>

unsigned long cat_at(int n, std::vector<unsigned long>& cat){
     unsigned long c = 0;
    for (int i = 0; i < n; i++){
        c += cat[i]*cat[n-1-i];
    }
    return c;
}

std::vector<unsigned long> catalan_numbers(int n){
    std::vector<unsigned long> cat{1};

    for (int i = 0; i < n; i++){
        cat.push_back(cat_at(i+1, cat));
    }
    return cat;
}


int count_op(std::string in){
    int cnt = 0;
    for (int i = 0; i < in.size(); i++){
        if (in[i]=='/'||in[i]=='+'||in[i]=='*'||in[i]=='-'){
            cnt++;
        }
    }
    return cnt;
}

int main() {
    std::ifstream infile;
    std::ofstream outfile;
    std::string in;
    infile.open("input.txt");
    outfile.open("output.txt");
    if (!infile.is_open()||!outfile.is_open()){
        return EXIT_FAILURE;
    }
    while (infile>>in){
        int n = count_op(in);
        std::vector<unsigned long> cat = catalan_numbers(n);
        outfile<<in<<"   ";
        outfile<<cat[n]<<std::endl;
    }
    infile.close();
    outfile.close();
}