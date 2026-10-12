#include <iostream>

bool check_validity(float source_x,float source_y,float dest_x, float dest_y);

int main() {
    float source_x, source_y, dest_x, dest_y;
    std::cout<<"Source?"<<std::endl;
    std::cin>>source_x>>source_y;
    std::cout<<"Destination?"<<std::endl;
    std::cin>>dest_x>>dest_y;
    if (check_validity(source_x, source_y, dest_x, dest_y)){
        std::cout<<"OK!"<<std::endl;
    }else{
        std::cout<<"No"<<std::endl;
    }
}

bool check_validity(float source_x,float source_y,float dest_x, float dest_y){
    if (dest_x > 8 || dest_x <0 || dest_y > 8 || dest_y < 0){
        return false;
    }else if (std::abs(dest_y - source_y) == 2 && std::abs(dest_x - source_x) == 1){
        return true;
    }else if (std::abs(dest_x - source_x) == 2 && std::abs(dest_y - source_y) == 1){
        return true;
    }
    return false;

}