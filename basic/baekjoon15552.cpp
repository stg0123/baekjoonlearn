#include <iostream>

using namespace std;
int main(){
    std::cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int a,b,n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> a >> b;
        std::cout << a+b << '\n';
    }
    
    return 0;


}