#include <iostream>
#include <vector>

int main(){
    int n, c=0;
    std::vector<int> v, location;
    std::cout<<"please enter a value"<<std::endl;
    std::cin>>n;

    for (int i = n; i > 0; i--){
        std::cout<<"enter number"<<std::endl;
        std::cin>>n;
        v.push_back(n);
    }

    std::cout<<"please enter s"<<std::endl;
    std::cin>>n;
    for (int i = 0; i < v.size(); i++){
        if (v.at(i)==n){
            c++;
            location.push_back(i);
        }
    }
if (c!=0){
    std::cout<<"the number "<<n<<" appears "<<c<<" times at: "<<std::endl;
    for (int i = 0; i < location.size(); i++){
            std::cout<<location.at(i)<<std::endl;
        }
}else{
    std::cout<<"the number "<<n<<" has no occurances"<<std::endl;
}
}