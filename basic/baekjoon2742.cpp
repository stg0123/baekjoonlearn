#include <iostream>

using namespace std;
int main(){
    std::cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    for(int i=n;i>=1;i--){
        std::cout << i << '\n';
    }
    
    return 0;


}