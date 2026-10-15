#include <iostream>
#include <vector>

int main() {
    int minnum, maxnum, n = -1, guess;
    std::cout << "range?" << std::endl;
    std::cin >> minnum >> maxnum;
    guess = maxnum;
    while (n != 0){
    std::cout<<"number is: "<<guess<<std::endl;
    std::cout<<"-1 small, 0 correct, 1 large"<<std::endl;
    std::cin>>n;
    if (n == -1){
        guess = guess + 1;
    } else if (n == 1){
        guess = guess - 1;
    }

    }
}