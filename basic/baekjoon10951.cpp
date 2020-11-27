#include <iostream>

using namespace std;
int main(){

    int a,b;
    while(1){
        std::cin >> a>> b;
        if(cin.fail())
            break;
        else 
            std::cout << a+b << '\n';

    }
    return 0;
}