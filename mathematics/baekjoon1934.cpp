#include <iostream>
#include <vector>
using namespace std;
int gcd(int a,int b){
    a=a%b;
    if(a==0)
        return b;
    else
        return gcd(b,a);
};

int main(){
    int n,a,b;
    std::cin >>n;
    for(int i=0;i<n;i++){
        std::cin >> a>>b;
        std::cout << a*b/gcd(a,b)<<'\n';

    }

    return 0;    
}