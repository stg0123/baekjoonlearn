#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
struct vec{
    int x,y;
    int index;
};
vec piv;
ll ccw(vec& v1,vec& v2,vec& v3){
    return 1LL*(v1.x*v2.y-v1.y*v2.x+v2.x*v3.y-v2.y*v3.x+v3.x*v1.y-v3.y*v1.x);
};
bool compare1(vec& v1,vec& v2){
    return v1.y==v2.y ? v1.x<v2.x : v1.y<v2.y;
};
ll distance(vec& v1,vec& v2){
    ll tmp1 =v1.x-v2.x;
    ll tmp2 =v1.y-v2.y;
    return tmp1*tmp1+tmp2*tmp2;  
};
bool compare2(vec& v1,vec& v2){
    ll tmp=ccw(piv,v1,v2);
    return tmp==0 ? distance(piv,v1)<distance(piv,v2) :tmp>0;
};

class multiangle{
private:
    vector<vec> point;
    int N;
public:
    multiangle(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int x,y;
        for(int i=0;i<N;i++){
            std::cin >> x >> y;
            point.push_back({x,y,i});
        }
        sort(point.begin(),point.end(),compare1);
        piv=point[0];
        sort(point.begin()+1,point.end(),compare2);
    }
    void print_sol(){
        int pt = point.size()-1;
        for(int i=1;i<point.size();i++){
            if(ccw(point[0],point[point.size()-i],point[point.size()-(i+1)])==0)
                pt--;
            else
                break;
        }
        reverse(point.begin()+pt,point.end());
        for(int i=0;i<point.size();i++)
            std::cout << point[i].index <<' ';
        std::cout << '\n';
    }

};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        multiangle ma;
        ma.print_sol();
    }

    return 0;
}