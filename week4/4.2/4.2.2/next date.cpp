#include <iostream>

bool leap_year(int year){
    bool ly = false;

    if (year % 4 == 0 && year % 100 != 0){
        ly = true;
    }else if (year % 400 == 0){
        ly = true;
    }

    return ly;
}

void next_day(int d1, int m1, int y1, int& d2, int& m2, int& y2){
        d2 = d1 + 1;
        m2 = m1;
        y2 = y1;
}

void next_month(int d1, int m1, int y1, int& d2, int& m2, int& y2){
            d2 = 1;
            m2 = m1 + 1;
            y2 = y1;
}

void next_year(int d1, int m1, int y1, int& d2, int& m2, int& y2){
            d2 = 1;
            m2 = 1;
            y2 = y1 + 1;
}

void next_date(int d1, int m1, int y1, int& d2, int& m2, int& y2){

    if (d1 < 28){
    next_day(d1, m1, y1, d2, m2, y2);  
    } else if (m1 == 2){
        if (!leap_year(y1) && d1 == 28){
            next_month(d1, m1, y1, d2, m2, y2);
        }
        else if (leap_year(y1) && d1 == 29){
            next_month(d1, m1, y1, d2, m2, y2);
        } else {
            next_day(d1, m1, y1, d2, m2, y2); 
        }
    }else if (d1 < 30){
        next_day(d1, m1, y1, d2, m2, y2); 
    }else{
        if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11){
            if (d1 < 31){
                next_day(d1, m1, y1, d2, m2, y2); 
            }else{
                next_month(d1, m1, y1, d2, m2, y2);
            }
        }else if (m1 == 12){
            if (d1 < 31){
                next_day(d1, m1, y1, d2, m2, y2); 
            }else{
            next_year(d1, m1, y1, d2, m2, y2);
            }
        }else{
            next_month(d1, m1, y1, d2, m2, y2);
        }
    }


}

int main(){
    int d1, m1, y1, d2, m2, y2;
    std::cout<<"give date:"<<std::endl;
    std::cin>>d1>>m1>>y1;
    next_date(d1, m1, y1, d2, m2, y2);
    std::cout<<"the next date is:"<<d2<<"/"<<m2<<"/"<<y2<<std::endl;
}