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
ll ccw(vec& v1,vec& v2,vec& v3){
    return ((v1.x*v2.y-v1.y*v2.x)+(v2.x*v3.y-v2.y*v3.x)+(v3.x*v1.y-v3.y*v1.x));
};
bool compare1(vec& v1,vec& v2){
    return v1.y==v2.y ? v1.x<v2.x : v1.y < v2.y;
};
bool compare2(vec& v1,vec& v2){
    ll tmp=ccw(piv,v1,v2);
    return tmp ==0 ? (v1.x+v1.y)<(v2.x+v2.y) : tmp >0;
};
class convechull_basic{
private:
    vector<vec> point;
    int N;
public:
    convechull_basic(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int x,y;
        for(int i=0;i<N;i++){
            std::cin >> x >> y;
            point.push_back({x,y});
        }
        sort(point.begin(),point.end(),compare1);
        piv = point[0];
        sort(point.begin()+1,point.end(),compare2);
    }
    void convex_hull(){
        stack<vec> st;
        st.push(point[0]);
        st.push(point[1]);
        vec first,second;
        for(int i=2;i<N;i++){
            while(st.size()>=2){
                second =st.top();
                st.pop();
                first = st.top();
                if(ccw(first,second,point[i])>0){
                    st.push(second);
                    break;
                }
            }
            st.push(point[i]);
        }
        std::cout << st.size()<<'\n';
    }
};
int main(){
    convechull_basic cb;
    cb.convex_hull();
    return 0; 
}