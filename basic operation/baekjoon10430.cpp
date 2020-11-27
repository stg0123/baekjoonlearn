#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int a,b,c;
    
    std::cin >> a >>b >> c;
    std::cout<< (a+b)%c << endl <<((a%c)+(b%c))%c << endl <<(a*b)%c << endl <<((a%c)*(b%c))%c;

    return 0;
}