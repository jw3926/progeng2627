#include <iostream>
//This is an answer checker which asks five questions and checks the answer (whether it is 2). If the answer is not valid (not between 1 to 3), it will be kept asking. 
int main(){
    int answer;
    int score = 0;
    for (int question = 0; question < 5; question ++){
    std::cout<<"Enter a number from 1 to 3"<<std::endl;
    std::cin>>answer;
    while (answer < 1 || answer > 3){
    std::cout<<"Invalid, enter a number from 1 to 3"<<std::endl;
    std::cin>>answer;
    }
    if (answer == 2){
        score ++;
    }}
    std::cout<<"Your score is: "<<score<<std::endl;

}