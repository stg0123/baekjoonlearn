#include <iostream>

using namespace std;
int main(){
    int n,n_1,n_2,tmp,count=0;
    std::cin >> n;
    tmp=n;
    while(1){
        if(n<10){
            n_1=0;
            n_2=n;
        }
        else{
            n_2=n%10;
            n_1=(n-n_2)/10;
        }
        n=n_2*10+((n_1+n_2)%10);
        count++;
        if(n==tmp)
            break;
    }
    std::cout <<count;
    return 0;
}