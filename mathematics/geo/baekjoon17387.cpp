#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class line_cross{
private:
    vector<pair<ll,ll>> point;
public:
    line_cross(){
        ll x,y;
        for(int i=0;i<4;i++){
            std::cin >> x>> y;
            point.push_back({x,y});
        }
    }
    int CCW(pair<ll,ll>& a,pair<ll,ll>& b,pair<ll,ll>& c){
        ll tmp =(a.first*b.second-a.second*b.first)+(b.first*c.second-b.second*c.first)+(c.first*a.second-c.second*a.first);
        if(tmp>0)
            return 1;
        else if(tmp <0)
            return -1;
        else
            return 0;
    }

    void find_cross(){
        int s1 = CCW(point[0],point[1],point[2])*CCW(point[0],point[1],point[3]);
        int s2 = CCW(point[2],point[3],point[0])*CCW(point[2],point[3],point[1]);

        if(s1==0 && s2==0){
            if(point[0]>point[1])
                swap(point[0],point[1]);
            if(point[2]>point[3])
                swap(point[2],point[3]);

            if(point[2]<=point[1] && point[0]<=point[3])
                std::cout << 1;
            else
                std::cout << 0;
        }
        else if(s1<=0&&s2<=0)
            std::cout << 1;
        else
            std::cout << 0;

    }
    /*
    a,c 방정식 (c.y-a.y)/(c.x-a.x) 기울기 -(c.x-a.x)/(c.y-a.y)
    c.y-a.y : a.x-c.x
    */
    
};
int main(){
    line_cross lc;
    lc.find_cross();

    return 0;
}