#include <iostream>

void sort_two_strings(std::string& s1, std::string& s2){
    std::string temp;
    temp = s1;
    s1 = s2;
    s2 = temp;
}

int main(){
    std::string n1, n2;
    std::cout << "please enter two strings:" << std::endl;
    std::cin >> n1 >> n2;
    sort_two_strings(n1, n2);
    std::cout << n1 << " " << n2 << std::endl;
}