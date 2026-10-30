#include <iostream>
#include <vector>

void append_vectors(const std::vector<int>& vin1, const int t, std::vector<int>& vout){
    for (int i = 0; i < vin1.size(); i++){
        if (vin1.at(i) < t){
        vout.push_back(vin1.at(i));}
    }
}


int main(){
    int n, t;
    double x;
    std::vector<int> v1, v2, vout;
    std::cout<<"please enter a value"<<std::endl;
    std::cin>>n;

    for (int i = n; i > 0; i--){
        std::cout<<"enter number"<<std::endl;
        std::cin>>x;
        v1.push_back(x);
    }
    std::cout<<"please enter a value"<<std::endl;
    std::cin>>t;

    append_vectors(v1, t, vout);
    std::cout<<"the result is: "<<std::endl;
    if (vout.size()!=0){
    for (int i = 0; i < vout.size(); i++){
    std::cout<<vout.at(i)<<std::endl;}}
    else{
        std::cout<<"NA"<<std::endl;
    }
}