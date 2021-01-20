#include <iostream>
using namespace std;
typedef long long ll;

class CCW{
private:
    int x1,y1;
    int x2,y2;
    int x3,y3;
public:
    CCW(){
        std::cin >> x1>>y1;
        std::cin >> x2>>y2;
        std::cin >> x3>>y3;
    }

    /*
    (x1,y1),(x2,y2),(x3,y3)의 이 순서대로 외적
    V1 = (x2-x1,y2-y1) ,V2=(x3-x2,y3-y2)
    V1xV2=(x2-x1 y2-y1 0 x2-x1)
          (x3-x2 y3-y2 0 x3-x2)
         =|(0,-0,(x2-x1)(y3-y2)-(y2-y1)(x3-x2))| //공식 중간부터 x(2번째) y(3번째) z(1번째) 순서
     정리=(x1*y2-x2*y1)+(x2*y3-x3*y2)+(x3*y1-x1*y3) 꼭 외우기      
    */

    int outer_product(){
        ll tmp = (x1*y2-x2*y1)+(x2*y3-x3*y2)+(x3*y1-x1*y3);
        if(tmp==0)
            return 0;
        else if(tmp >0)
            return 1;
        else 
            return -1;
    }

};
int main(){
    CCW ccw;
    std::cout << ccw.outer_product();
    return 0;
}