#include <iostream>

using namespace std;
int main(){
    int n,idx=0;
    std::cin >>n;
    while(1){
        idx++;
        if(n<=idx*(idx+1)/2)
            break;
    }
    int tmp=n-idx*(idx-1)/2;
    if(idx%2==0)
        std::cout <<tmp << '/'<< idx+1-tmp;
    else
        std::cout <<idx+1-tmp<<'/'<<tmp;
    
    



    return 0;
}