#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef long double ld;
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

            if(point[2]<=point[1] && point[0]<=point[3]){
                std::cout << 1;
                if(CCW(point[2],point[3],point[0])!=0||CCW(point[2],point[3],point[1])!=0){
        
                    cal_cross_point(point[0],point[1],point[2],point[3]);
                }
                else if(point[0]==point[3])
                    std::cout <<'\n'<< point[0].first << ' '<<point[0].second;
                else if(point[1]==point[2])
                    std::cout <<'\n'<< point[1].first << ' '<<point[2].second;
            }       
            else
                std::cout << 0;
        }
        else if(s1<=0&&s2<=0){
            std::cout << 1;
            cal_cross_point(point[0],point[1],point[2],point[3]);
        }
        else
            std::cout << 0;

    }
    /*
    a,b 직선의 방정식 y=ax+b,y=cx+d 연립 x=(d-b)/(a-c)
    y=(b.second-a.second)/(b.first-a.first)(x-a.first)+a.second
    y=(d.second-a.second)/(d.first-a.first)(x-c.first)+c.second
    */
    void cal_cross_point(pair<ll,ll>& a,pair<ll,ll>& b,pair<ll,ll>& c,pair<ll,ll>& d){
        
        cout.precision(12);
        if(b.first==a.first){
            double tmp=(d.second-c.second)/(double)(d.first-c.first);
            std::cout<< '\n'<<a.first <<' '<< tmp*(a.first-c.first)+c.second;
            return ;
        }
            
        double gr1=(b.second-a.second)/(double)(b.first-a.first);
        double con1=a.second-gr1*a.first;
        
        if(c.first==d.first){
            std::cout << '\n'<<c.first <<' '<< gr1*(c.first-a.first)+a.second;
            return;
        }
        double gr2=(d.second-c.second)/(double)(d.first-c.first);
        double con2=c.second-gr2*c.first;
    
        
        pair<double,double> sol;
        sol.first=(con2-con1)/(gr1-gr2);
        sol.second=gr1*(sol.first-a.first)+a.second;
        std::cout << '\n' <<sol.first << ' ' << sol.second << '\n';
        
    }


};
int main(){
    line_cross lc;
    lc.find_cross();

    return 0;
}