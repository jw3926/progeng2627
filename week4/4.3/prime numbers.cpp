#include <iostream>
#include <cmath>

int isprime(int n){
    for (int i = 1; i < std::sqrt(n)+1; i++){
        if (n % i == 0 && i != 1){
            return i;
        }
        
    }
    return 1;
}

int main(){
    
    int n;

    std::cout<<"Type number"<<std::endl;
    std::cin>>n;

    while(n<1){
        std::cout<<"Invalid"<<std::endl;
        std::cin>>n;
    }
    int p = isprime(n);
    if (isprime(n) == 1){
        std::cout<<"not prime"<<std::endl;
    }else{
        std::cout<<"prime is: "<<isprime(n)<<std::endl;
    }
    

}