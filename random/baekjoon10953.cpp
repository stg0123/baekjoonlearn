#include <iostream>
using namespace std;
int main(){
    int n,a,b;
    std::cin >> n;
    for(int i=0;i<n;i++){
        scanf("%d,%d",&a,&b);
        std::cout << a+b<<'\n';
        
    }

    return 0;
}