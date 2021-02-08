#include <iostream>
using namespace std;
int main(){
    int tmp;
    int sol=0;
    for(int i=0;i<5;i++){
        std::cin >> tmp;
        sol+=(tmp*tmp)%10;
    }
    std::cout<< sol%10 ;


    return 0;
}