#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int x,y,w,h;
    std::cin >> x >> y >> w >>h;
    
    std::cout << min(min(x,w-x),min(y,h-y));




    return 0;
}