#include <iostream>

using namespace std;
int main(){
    int x[3],y[3];
    for(int i=0;i<3;i++){
        std::cin >> x[i] >> y[i];
    }
    if(x[0]==x[1])
        std::cout << x[2]<<' ';
    else if(x[0]==x[2])
        std::cout << x[1]<<' ';
    else 
        std::cout << x[0]<<' ';
    
    if(y[0]==y[1])
        std::cout << y[2]<<' ';
    else if(y[0]==y[2])
        std::cout << y[1]<<' ';
    else 
        std::cout << y[0]<<' ';

    return 0;

}