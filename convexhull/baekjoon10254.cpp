#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
struct vec{
    ll x,y;
};
vec piv;
ll ccw(vec v1,vec v2,vec v3){
    return 1LL*(v1.x*v2.y-v1.y*v2.x+v2.x*v3.y-v2.y*v3.x+v3.x*v1.y-v3.y*v1.x);
};
bool compare1(vec& v1,vec& v2){
    return v1.y==v2.y ? v1.x<v2.x : v1.y <v2.y;
};
bool compare2(vec& v1,vec& v2){
    ll tmp=ccw(piv,v1,v2);
    return tmp==0 ? v1.x+v1.y<v2.x+v2.y : tmp>0;
};
class load{
private:
    vector<vec> point;
    int N;
public:
    load(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int x,y;
        for(int i=0;i<N;i++){
            std::cin >> x>> y;
            point.push_back({x,y});
        }
        sort(point.begin(),point.end(),compare1);
        piv=point[0];
        sort(point.begin()+1,point.end(),compare2);
    }
    ll distance(vec& v1,vec& v2){
        ll tmp1=v1.x-v2.x;
        ll tmp2=v1.y-v2.y;
        return tmp1*tmp1+tmp2*tmp2;
    };
    void convexhull(){
        stack<vec> st;
        st.push(point[0]);
        st.push(point[1]);
        vec first,second;
        for(int i=2;i<N;i++){
            while(st.size()>=2){
                second = st.top();
                st.pop();
                first = st.top();
                if(ccw(first,second,point[i])>0){
                    st.push(second);
                    break;
                }
            }
            st.push(point[i]);
        }
        vector<vec> v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        };
        vec sol1,sol2;
        ll max_dis=0;
        int j=1;
        for(int i=0;i<v.size()-1;i++){
            int next_i=(i+1)%v.size();
            while(1){
                int next_j = (j+1)%v.size();
                first.x = v[next_i].x- v[i].x;
                first.y = v[next_i].y- v[i].y;

                second.x = v[next_j].x- v[j].x;
                second.y = v[next_j].y- v[j].y;
                
                if(ccw({0,0},first,second)<0)
                    j=next_j;
                else
                    break;
            }
            ll tmp=distance(v[i],v[j]);
            if(tmp >max_dis){
                max_dis=tmp;
                sol1=v[i];
                sol2=v[j];
            }
        }
        std::cout << sol1.x << ' ' << sol1.y  << ' ' << sol2.x << ' ' << sol2.y << '\n';
    }

};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        load ld;
        ld.convexhull();
    }


    return 0;
}