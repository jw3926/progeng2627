#include <vector>
#include <iostream>

int min_vector_element(const std::vector<double>& vin){
    if (vin.size()==0){
        return -1;
    }
    double min = vin[0];
    int index = 0;
    for (int i = 0; i<vin.size(); i++){
        if (vin[i] < min){
            min == vin[i];
            index = i;
        }
    }
    return index;
}

int main(){
    int n;
    double x;
    std::vector<double> v{};
    std::cout<<"please enter a value"<<std::endl;
    std::cin>>n;

    for (int i = n; i > 0; i--){
        std::cout<<"enter number"<<std::endl;
        std::cin>>x;
        v.push_back(x);
    }
    std::cout<<"min is at: "<<min_vector_element(v)<<std::endl;
}