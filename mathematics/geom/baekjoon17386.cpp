#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class line_cross{
private:
    vector<pair<ll,ll>> point;
public:
    line_cross(){
        int x,y;
        for(int i=0;i<4;i++){
            std::cin >> x >> y;
            point.push_back({x,y});
        }
    }
    int CCW(pair<ll,ll>& a,pair<ll,ll>& b,pair<ll,ll>& c){
        ll tmp = (a.first*b.second-a.second*b.first)+(b.first*c.second-b.second*c.first)+(c.first*a.second-c.second*a.first);
        if(tmp>0) // 반시계
            return 1;
        else if(tmp<0) // 시계
            return -1;
        else
            return 0; // 일직선
    }
    void find_cross(){
        if(CCW(point[0],point[1],point[2])*CCW(point[0],point[1],point[3])<=0)
            if(CCW(point[2],point[3],point[0])*CCW(point[2],point[3],point[1])<=0){
                std::cout<<1 ;
                return ;
            }
        std::cout << 0;
        return ; 
                

    }

};
int main(){
    line_cross lc;
    lc.find_cross();

    return 0;
}

