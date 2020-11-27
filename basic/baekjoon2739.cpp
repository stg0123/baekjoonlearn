#include <iostream>

using namespace std;
int main(){
    int x;
    std::cin >> x;
    for(int i=1;i<=9;i++)
        std::cout << x << " * " << i << " = "<< x*i << endl;

    return 0;


}