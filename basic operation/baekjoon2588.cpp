#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int a,b;
    std::cin >> a >> b;
    int b_1=b%10;
    int b_10=((b%100)-b_1)/10;
    int b_100=(b-b_1-b_10)/100;
    std::cout << a*b_1 << endl << a*b_10 << endl << a*b_100 << endl << a*b;   

    return 0;
}