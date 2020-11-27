#include <iostream>

using namespace std;
int main(){
    std::cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n,x,tmp;
    std::cin >> n >> x;
    for(int i=1;i<=n;i++){
        std::cin >> tmp;
        if(tmp<x)
            std::cout << tmp << ' ';
    }
    
    return 0;


}