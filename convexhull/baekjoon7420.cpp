#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#define PI 3.141592
using namespace std;
typedef long long ll;
struct vec{
    int x,y;
};
vec piv;
ll ccw(vec& v1,vec& v2,vec& v3){
    return 1LL*(v1.x*v2.y-v1.y*v2.x+v2.x*v3.y-v2.y*v3.x+v3.x*v1.y-v3.y*v1.x);
};
bool compare1(vec& v1,vec& v2){
    return v1.y==v2.y ? v1.x<v2.x : v1.y<v2.y;
};
bool compare2(vec& v1,vec & v2){
    ll tmp=ccw(piv,v1,v2);
    return tmp==0 ? v1.x+v1.y<v2.x+v2.y : tmp>0; 
};
class barrier{
private:
    vector<vec> point;
    int N,L;
public:
    barrier(){
        std::cin >>  N >> L;
        set_val();
    }
    void set_val(){
        int x,y;
        for(int i=0;i<N;i++){
            std::cin >> x >> y;
            point.push_back({x,y});
        }
        sort(point.begin(),point.end(),compare1);
        piv=point[0];
        sort(point.begin()+1,point.end(),compare2);
    }
    double distance(vec& v1,vec& v2){
        ll tmp1=v1.x-v2.x;
        ll tmp2=v1.y-v2.y;
        return sqrt(tmp1*tmp1+tmp2*tmp2);
    }
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
        double sol=0;
        vec tmp =st.top();
        first =st.top();
        st.pop();
        while(!st.empty()){
            second= st.top();
            sol+= distance(first,second);
            first= second;
            st.pop();
        }
        sol+= distance(first,tmp);
        sol+= PI*2*L;
        std::cout << round(sol)<<'\n';
    }

};
int main(){
    barrier br;
    br.convexhull();

    return 0;
}