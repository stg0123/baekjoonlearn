#include <iostream>

using namespace std;
int main(){
    int n,idx=0;
    long long sum=1;
    std::cin >> n;
    if(n==1)
        std::cout << 1;
    else{  
    while(1){
        idx++;
        sum+=idx*6;
        if(n<=sum){
            std::cout << idx+1;
            break;
        }       
    }
    }


    return 0;
}