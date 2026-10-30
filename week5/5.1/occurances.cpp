#include <iostream>
#include <vector>

int main(){
    int n, c=0;
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
    for (int i = 0; i < v.size(); i++){
        if (v.at(i)==n){
            c++;
        }
    }
    if (c!=0){
    std::cout<<"the number "<<n<<" appears "<<c<<" times"<<std::endl;
}else{
    std::cout<<"the number "<<n<<" has no occurances"<<std::endl;
}
}