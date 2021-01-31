#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
class polyangle{
private:
    vector<pair<ll,ll>> point;
    int N;
public:
    polyangle(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int x,y;
        for(int i=0;i<N;i++){
            std::cin >> x>>y;
            point.push_back({x,y});
        }
    }
    /*
    v1= (a.x-c.x,a.y-c.y,0) v2=(b.x-c.x,b.y-c.y,0)
    CCW = A,B,C (a.x*b.y-a.y*b.x)+(b.x*c.y-b.y*c.x)+(c.x*a.y-c.y*.a.x)
    외우자
    */
    double outer_product(pair<int,int> a,pair<ll,ll>& b,pair<ll,ll>& c){
        double tmp= (a.first*b.second-a.second*b.first)+(b.first*c.second-b.second*c.first)+(c.first*a.second-c.second*a.first);
        return tmp/2;
    }

    void cal_area(){
        double sol=0;
        for(int i=0;i<N;i++){
            if(i==N-1)
                sol+=outer_product({0,0},point[i],point[0]);
            else
                sol+=outer_product({0,0},point[i],point[i+1]);
        }
        printf("%.1lf",abs(sol));
    }

};
int main(){
    polyangle pl;
    pl.cal_area();
    return 0;
}