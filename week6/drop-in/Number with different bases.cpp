#include <vector>
#include <iostream>
#include <cmath>

bool digits_in_base(int n, int b, std::vector<int>& digits){
    
    if (n < 0){
        n = -n;
    }
    
    if (b < 2 || b > 16){
        return false;
    }
    while (n != 0){
        digits.push_back(n % b);
        n = n / b;
    }
    
    return true;
    

}

int digits_to_decimal(std::vector<int>& digits, int base){
    int decimal = 0;
    for (int i = 0; i<digits.size(); i++){
        decimal += digits.at(i) * pow(base, i);
    }
    return decimal;
}

bool convert_base(std::vector<int>& digits1, int b1, int b2, std::vector<int>& digits2){
    if (b1 < 2 || b1 > 16 || b2 < 2 || b2 > 16){
        return false;
    }
    int decimal;
    decimal = digits_to_decimal(digits1, b1);
    digits_in_base(decimal, b2, digits2);
    return true;
}

void print_digits_as_number (const std::vector<int>& digits){
    std::vector<char> chars {'A','B','C','D','E','F'};
    for (int i = digits.size()-1; i > -1; i--){
        if (digits.at(i) < 10){
            std::cout<<digits.at(i)<<"";
        }else{
            std::cout<<chars.at(digits.at(i)-10);
        }
    }
    std::cout<<std::endl;
}




int main() {
    int num = 250;
    std::vector<int> octal_digits;
    std::vector<int> hex_digits;

    /// Obtain the octal digits of 250
    digits_in_base(num, 8, octal_digits);

    std::cout << "Octal: ";
    print_digits_as_number(octal_digits);

    /// Convert the octal digits to hexadecimal digits
    if (convert_base(octal_digits, 8, 16, hex_digits)) {
        std::cout << "Hexadecimal: ";
        print_digits_as_number(hex_digits);
    } else {
        std::cout << "Invalid base" << std::endl;
    }

    return 0;
}