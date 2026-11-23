#include <vector>
#include <iostream>
#include <cmath>

int bin_to_dec(std::vector<int>& in){
    int n = 0;
    std::vector<int> tmp;
    for (int i = in.size() - 1; i > -1; i--){
        //std::cout<<in[i]<<n<<std::endl;
        //std::cout<<n<<std::endl;
        n += in.at(i) * pow(2, in.size() - 1 - i);
    }
    return n;
}
std::vector<int> dec_to_bin(int n){
    std::vector<int> tmp;
    int rem = -1;
    while (n != 0){
    rem = n % 2;
    //std::cout<<rem<<std::endl;
    tmp.push_back(rem);
    n = n / 2;
    }
    return tmp;
}
void next_binary(std::vector<int>& in){
    int n = bin_to_dec(in);
    n += 1;
    std::vector<int> tmp = dec_to_bin(n);
    int gap = in.size() - tmp.size();
    if (gap > 0){
        for (int i = 0; i < gap; i++){
            tmp.push_back(0);
    }
    }
    in.clear();
    for (int i = tmp.size() - 1; i > -1; i--){
        in.push_back(tmp.at(i));
    }
    
}

bool rows_in_order(std::vector<std::vector<int>> in, int& index){
    index = -1;
    for (int i = 0; i < in.size() - 1; i++){
        next_binary(in.at(i));
        std::cout<<in[i][0]<<in[i][1]<<in[i][2]<<in[i][3]<<std::endl;
        if (in.at(i) != in.at(i+1)){
            index = i + 1;
            return false;
        }
    }
    return true;
}

int largest_gap(std::vector<std::vector<int>> in){
    int gap = 0;
    int tmp;
    for (int i = 0; i < in.size() - 1; i++){
        tmp = bin_to_dec(in[i+1]) - bin_to_dec(in[i]) - 1;
        if (gap < tmp){
            gap = tmp;
        }
    }
    return gap;
}
int main() {
    std::vector<std::vector<int>> matrix = {
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 0}
    };

    int gap = largest_gap(matrix);

    std::cout << "Largest gap: " << gap << std::endl;

    return 0;
}