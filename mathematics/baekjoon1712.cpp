#include <iostream>


using namespace std;
int main(){
    int A,B,C;
    int n=0;
    std::cin >>A>>B>>C;
    if(C-B>0)
        std::cout <<A/(C-B)+1;
    else
        std::cout << -1;

    return 0;
}