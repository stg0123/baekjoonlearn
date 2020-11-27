#include <iostream>

using namespace std;
int main(){
    int a,f=0;
    std::cin >> a;
    if(a%4==0)
        if(a%100==0){
            if(a%400==0)
                f=1;
        }
        else
            f=1;

    if(f)
        std::cout<<1;
    else
        std::cout<<0;
      

    return 0;
}