#include <iostream>

using namespace std;
int main(){
    int x,y,f;
    std::cin >> x >>y;
    if(x>0)
        if(y>0)
            f=1;
        else
            f=4;
    else
        if(y>0)
            f=2;
        else
            f=3;
    std::cout <<f;
    return 0;
}