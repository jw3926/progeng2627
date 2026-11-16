#include <vector>
#include <iostream>


unsigned long cat_at(int n, std::vector<unsigned long>& cat){
     unsigned long c = 0;
    for (int i = 0; i < n; i++){
        c += cat[i]*cat[n-1-i];
    }
    return c;
}
std::vector<unsigned long> catalan_numbers(int n){
    std::vector<unsigned long> cat{1};

    for (int i = 0; i < n; i++){
        cat.push_back(cat_at(i+1, cat));
    }
    return cat;
}




int main() {
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::vector<unsigned long> numbers = catalan_numbers(n);

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << "C" << i << " = " << numbers[i] << std::endl;
    }

    return 0;
}