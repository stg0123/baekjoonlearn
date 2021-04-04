#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int N;
    std::cin >> N;
    int size = (int)ceil(log2(N));
    int minsize = N&-N;
    int cnt=0;
    while(minsize^1){
        minsize>>=1;
        cnt++;
    }
    std::cout << (int)(1<<size)   << ' ' <<size-cnt;

    return 0;
}