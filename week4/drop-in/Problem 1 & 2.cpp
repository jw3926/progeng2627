#include <iostream>
#include <cstdlib>
#include <ctime>

bool check_validity(float source_x,float source_y,float dest_x, float dest_y);



int main() {
    std::time_t start = std::time(nullptr);
    int steps = 0;
    int curr_x, curr_y, dest_x, dest_y, org_x, org_y;
    bool end = false;
    bool reset = false;

    srand(time(nullptr));

    curr_x = rand() % 8 + 1;
    org_x = curr_x;
    curr_y = rand() % 8 + 1;
    org_y = curr_y;

    while (!end){
        if (reset){
            reset = false;
            steps = 0;
            curr_x = org_x;
            curr_y = org_y;
            start = std::time(nullptr);
            std::cout<<"You failed."<<std::endl;
        }
        std::cout<<"The current position is ("<<curr_x<<", "<<curr_y<<"), next step?"<<std::endl;
        std::cout<<"Your step count is: "<<steps<<std::endl;
        std::cin>>dest_x>>dest_y;
        while ((!check_validity(curr_x,curr_y, dest_x, dest_y))){
        std::cout<<"Invalid! The current position is ("<<curr_x<<", "<<curr_y<<"), next step?"<<std::endl;
        std::cin>>dest_x>>dest_y;
        }
        steps += 1;
        curr_x = dest_x;
        curr_y = dest_y;
        if ((curr_x == 1 && curr_y == 9) || (curr_x == 9 && curr_y == 1) || (curr_x == 9 && curr_y == 9) || (curr_x == 1 && curr_y == 1)){
            end = true;
        }
        if (steps > 4){
            reset = true;
        }
    }

    std::cout<<"You take "<<steps<<" steps in "<< std::time(nullptr) - start<<" seconds to reach the corner."<<std::endl;

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