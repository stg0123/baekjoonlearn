#include <iostream>

using namespace std;
int main(){
    std::cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int a,b;
    while(1){
        std::cin >> a>> b;
        if(a==0&&b==0)
            break;
        else 
            std::cout << a+b << '\n';

    }
    return 0;

}