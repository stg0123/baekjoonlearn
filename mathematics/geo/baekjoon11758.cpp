#include <iostream>
using namespace std;
int main(){
    int x1,x2,x3;
    int y1,y2,y3;
    std::cin >> x1>>y1;
    std::cin >> x2>>y2;
    std::cin >> x3>>y3;
    if((x2-x1)*(y3-y1)==(y2-y1)*(x3-x1))
        std::cout << 0<<'\n';
    else if((x2-x1)*(y3-y1)>(y2-y1)*(x3-x1))
        std::cout << 1<<'\n';
    else
        std::cout << -1<<'\n';
    return 0;
}