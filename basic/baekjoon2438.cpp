#include <iostream>

using namespace std;
int main(){
    std::cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int a,b,n;
    std::cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            std::cout << '*';
        std::cout << '\n';
    }
    
    return 0;


}