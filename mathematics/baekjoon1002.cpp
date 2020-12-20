#include <iostream>
#include <vector>

using namespace std;
int main(){
    int x1,y1,r1,x2,y2,r2;
    int n;
    std::cin >>n;
    for(int i=0;i<n;i++){
        std::cin >>x1>>y1>>r1>>x2>>y2>>r2;
        int dis =(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        if(x1==x2&&y1==y2&&r1==r2)
            std::cout << -1<<'\n';
        else if(dis>(r1+r2)*(r1+r2)||dis<(r1-r2)*(r1-r2))
            std::cout << 0<<'\n';
        else if(dis==(r1+r2)*(r1+r2)||dis==(r1-r2)*(r1-r2))
            std::cout << 1<<'\n';
        else
            std::cout << 2<<'\n';
    }

    return 0;
}
