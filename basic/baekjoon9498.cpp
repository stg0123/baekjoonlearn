#include <iostream>

using namespace std;
int main(){
    int a;
    std::cin >> a;
    a/=10;
    switch(a){
        case 10:
        case 9:
            std::cout << 'A';
            break;
        case 8:
            std::cout << 'B';
            break;
        case 7:
            std::cout << 'C';
            break;
        case 6:
            std::cout << 'D';
            break;
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:
            std::cout << 'F';
            break;
    }

    return 0;
}