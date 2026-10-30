#include <vector>
#include <iostream>

int search_vector_element(const int n, const std::vector<int>& vin){
    if (vin.size()==0){
        return -1;
    }
    for (int i = 0; i<vin.size(); i++){
        if (vin[i] == n){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    double x;
    std::vector<int> v{};
    std::cout<<"please enter a value"<<std::endl;
    std::cin>>n;

    for (int i = n; i > 0; i--){
        std::cout<<"enter number"<<std::endl;
        std::cin>>x;
        v.push_back(x);
    }
    std::cout<<"search for?"<<std::endl;
    std::cin>>n;
    std::cout<<"it is at: "<<search_vector_element(n, v)<<std::endl;
}