#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int n, maxnum;
    std::cout << "number?" << std::endl;
    std::cin >> n;
    maxnum = n;
    while (n != 1){
        if (n % 2 == 0){
            n = n / 2;
        }else{
            n = 3 * n + 1;
        }
        if (maxnum < n){
            maxnum = n;
        }
        numbers.push_back(n);
    }
    for (int i = 0; i < numbers.size(); i++){
        std::cout<<numbers[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"max is: "<<maxnum<<std::endl;
    std::cout << numbers.size() << " steps" << std::endl;
}