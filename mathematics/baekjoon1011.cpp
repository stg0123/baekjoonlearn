#include <iostream>
#include <math.h>

using namespace std;
void calculator(){
    long long x,y;
    std::cin >>x>>y;
    long long d=y-x;
    int n=1;
    
    while(1){
        n++;
        if(pow(n,2)>d)
            break;
    }
    
    if(pow(n-1,2)==d)
        std::cout << 2*(n-1)-1<<'\n';
    else if(d<=(pow(n-1,2)+pow(n,2))/2)
        std::cout << 2*n-2<<'\n';
    else 
        std::cout << 2*n-1<<'\n';


};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++)
        calculator();

    return 0;
}