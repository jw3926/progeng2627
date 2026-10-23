#include <iostream>
#include <cmath>

int sum_of_power(int n, int x);

int main(){
    int n, x;
    std::cin>>x>>n;
    std::cout<<sum_of_power(n, x)<<std::endl;
}

int sum_of_power(int n, int x){
    int result;
    for (int i = 1; i < n + 1; i++){
        result += pow(x, i);
    }
    return result;
}