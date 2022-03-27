#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,M;
    std::cin >> N >> M;
    if(N==1)
        std::cout << 1 <<'\n';
    else if (N==2)
        std::cout << min(4,(M+1)/2)<<'\n';
    else{
        if(M<=6)
            std::cout << min(4,M);
        else
            std::cout << M-2;
    }

    return 0;
}