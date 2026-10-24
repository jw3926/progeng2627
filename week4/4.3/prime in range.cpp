#include <iostream>
#include <cmath>

int isprime(int n){
    for (int i = 1; i < std::sqrt(n) + 1; i++){
        if (n % i == 0 && i != 1){
            return i;
        }
        
    }
    return 1;
}

int main(){
    
    int n1, n2;

    std::cout<<"Type number"<<std::endl;
    std::cin>>n1>>n2;

    while(n1 < 1 || n2 < 1){
        std::cout<<"Invalid"<<std::endl;
        std::cin>>n1>>n2;
    }
    if (n1 < n2){
        for (int i = n1; i < n2 + 1; i++){
            if (isprime(i) == 1){
                std::cout<<i<<std::endl;
            }
        }
    }else{
        for (int i = n2; i < n1 + 1; i++){
            if (isprime(i) == 1){
                std::cout<<i<<std::endl;
            }
        }
    }
    

}