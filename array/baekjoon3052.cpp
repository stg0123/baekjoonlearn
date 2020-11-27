#include <iostream>

using namespace std;
int main(){
    int a[42]={};
    int n,count=0;
    for(int i=0;i<10;i++){
        std::cin >>n;
        a[n%42]++;
    }
    for(int i=0;i<42;i++)
        if(a[i])
            count++;

    std::cout<< count;
        
    return 0;
}