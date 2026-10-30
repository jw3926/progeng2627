#include <iostream>
#include <vector>

int main(){
    int n;
    std::vector<int> v;
    std::cout<<"please enter a value"<<std::endl;
    std::cin>>n;

    for (int i = n; i > 0; i--){
        std::cout<<"enter number"<<std::endl;
        std::cin>>n;
        v.push_back(n);
    }

    std::cout<<"please enter s"<<std::endl;
    std::cin>>n;
    std::cout<<"numbers smaller than "<<n<<" are: "<<std::endl;
    for (int i = 0; i < v.size(); i++){
        if (v.at(i)<n){
            std::cout<<v.at(i)<<std::endl;
        }
    }
}