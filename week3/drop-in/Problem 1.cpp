#include <iostream>
#include <cmath>
bool valid_triangle(float a, float b, float c);

int main() {
double a, b, x, c, perimeter, s, area;
std::cout<<"Sides?"<<std::endl;
std::cin>>a>>b>>c;
if (valid_triangle(a, b, c)){
    std::cout<<"It is a ";
    if (a == b && a == c){
        std::cout<<"equilateral";
    }else if (a == b || a == c || b == c){
        std::cout<<"isosceles";
    }else{
        std::cout<<"scalene";
    }
    std::cout<<" triangle"<<std::endl;
    perimeter = a + b + c;
    std::cout<<"Perimeter is "<<perimeter<<std::endl;
    s = 0.5 * (a + b + c);
    area = std::sqrt(s * (s - a) * (s - b) * (s - c));
    std::cout<<"Area is "<<area<<std::endl;
}else{
    std::cout<<"It is not a traingle!"<<std::endl;
}
}

bool valid_triangle(float a, float b, float c){
    if (a + b > c && a + c > b && b + c > a){
        return true;
    }else{
        return false;
    }
}

