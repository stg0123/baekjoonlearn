#include <iostream>
int main(){
    int n,sol=0;
    std::cin >> n;
    n=1000-n;
    sol+=n/500;
    n%=500;
    sol+=n/100;
    n%=100;
    sol+=n/50;
    n%=50;
    sol+=n/10;
    n%=10;
    sol+=n/5;
    sol+=n%5;
    std::cout << sol;
    return 0;
}