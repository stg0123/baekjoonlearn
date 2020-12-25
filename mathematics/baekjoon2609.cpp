#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a,int b){
    int tmp;
    while(1){
        tmp=b;
        b=a%b;
        a=tmp;
        if(b==0)
            break;
    }
    std::cout << a<<'\n';
    return a;
}


int main(){
    int a,b,tmp;
    std::cin >> a >>b;
    if(a<b){
        tmp=a;
        a=b;
        b=tmp;
    }
    std::cout << a*b/gcd(a,b)<<'\n';
    return 0;
}