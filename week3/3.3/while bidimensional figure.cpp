#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int c = 0, c2 = 0;
    // n times we draw one row
    // note that we need a different variable
    // for the loop counter
    while (c2 < n){

        // the following loop draws one row
        while(c < n){
            std::cout << "*"; 
            // there is no << std::endl
            // because we want them on the same row
            c++;
        };
        c = 0;
        std::cout << std::endl;
        // we go on a newline after each row
        c2++;
    }

}