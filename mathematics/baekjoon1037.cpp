#include <iostream>
using namespace std;
int main(){
    int n,min=1000000,max=1;
    std::cin >>n;
    int a;
    for(int i=0;i<n;i++){
        std::cin>>a;
        if(a<min)
            min=a;
        if(a>max)
            max=a;
    }
    std::cout << min*max<<'\n';
    return 0;
}