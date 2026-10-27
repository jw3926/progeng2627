#include <iostream>


int gcd(int a, int b){
    if(a<b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    int rem = a % b;
    while (rem != 0){
        a = b;
        b = rem;
        rem = a % b;
    }
    return b;
}

int euler_totient(int n){
    int count = 0;
    if (n == 1){
        return 1;
    }
    for (int i = 1; i < n; i++){
        if (gcd(i,n)==1){
            count ++;
        }
    }

    return count;

}

int totient_sum(int n, int &depth){
    depth = 0;
    int sum = 0;
    while (n != 1){
        n = euler_totient(n);
        depth++;
        sum = sum + n;
    }
    return sum;
}

int find_peak(int a, int b){
    double max_peak = 0;
    int depth;
    double peak;
    int max_x = -1;
    int depth_x, depth_x_m_1, depth_x_p_1;
    for (int i = a; i < b; i++){
        totient_sum(i, depth_x);
        totient_sum(i-1, depth_x_m_1);
        totient_sum(i+1, depth_x_p_1);
        if (depth_x > depth_x_m_1 && depth_x > depth_x_p_1 ){
        peak = (depth_x-depth_x_m_1+depth_x-depth_x_p_1)/2;
        if (peak>max_peak){
            max_peak = peak;
            max_x = i;
        }}
    }
    return max_x;
}

int main(){
    int a, b, max_x;
    std::cin>>a>>b;
    max_x = find_peak(a, b);
    if (max_x == -1){
        std::cout<<"-1"<<std::endl;
        return 0;
    }
    int depth_x, depth_x1, depth_x_1;
    totient_sum(max_x-1, depth_x_1);
    totient_sum(max_x, depth_x);
    totient_sum(max_x+1, depth_x1);
    std::cout << max_x << " "<< depth_x << " "<< depth_x_1 << " "<< depth_x1 << std::endl;
}