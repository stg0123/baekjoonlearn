#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
struct vec{
    int x,y;
    bool operator < (vec & a){
        return x==a.x? y<a.y : x<a.x;
    };
    bool operator == (vec & a){
        return x==a.x&&y==a.y;
    }
};
vec piv;
ll ccw(vec& v1,vec& v2,vec& v3){
    return 1LL*(v1.x*v2.y-v1.y*v2.x+v2.x*v3.y-v2.y*v3.x+v3.x*v1.y-v3.y*v1.x);
};
bool compare1(vec& v1,vec& v2){
    return v1.y==v2.y ? v1.x<v2.x : v1.y<v2.y;
};
bool compare2(vec& v1,vec& v2){
    ll tmp=ccw(piv,v1,v2);
    return tmp==0 ? v1.x+v1.y <v2.x+v2.y : tmp>0;
};
class dot_separate{
private:
    vector<vec> w_point;
    vector<vec> b_point;
    int WN,BN;
public:
    dot_separate(){
        std::cin >> WN >> BN;
        set_val();
    }
    void set_val(){
        int x,y;
        for(int i=0;i<WN;i++){
            std::cin >>x >> y;
            w_point.push_back({x,y});
        }
        sort(w_point.begin(),w_point.end(),compare1);
        piv = w_point[0];
        sort(w_point.begin()+1,w_point.end(),compare2);
        for(int i=0;i<BN;i++){
            std::cin >> x >> y;
            b_point.push_back({x,y});
        }
        sort(b_point.begin(),b_point.end(),compare1);
        piv=b_point[0];
        sort(b_point.begin()+1,b_point.end(),compare2);
    }
    void convexhull(){
        stack<vec> st_w;
        stack<vec> st_b;
        vec first,second; 
        st_w.push(w_point[0]);
        if(w_point.size()>1)
            st_w.push(w_point[1]);
        for(int i=2;i<WN;i++){
            while(st_w.size()>=2){
                second = st_w.top();
                st_w.pop();
                first =st_w.top();
                if(ccw(first,second,w_point[i])>0){
                    st_w.push(second);
                    break;
                }
            }
            st_w.push(w_point[i]);
        }
        st_b.push(b_point[0]);
        if(b_point.size()>1)
            st_b.push(b_point[1]);
        for(int i=2;i<BN;i++){
            while(st_b.size()>=2){
                second = st_b.top();
                st_b.pop();
                first =st_b.top();
                if(ccw(first,second,b_point[i])>0){
                    st_b.push(second);
                    break;
                }
            }
            st_b.push(b_point[i]);
        }
        vector<vec> w_v,b_v;
        while(!st_w.empty()){
            w_v.push_back(st_w.top());
            st_w.pop();
        }
        while(!st_b.empty()){
            b_v.push_back(st_b.top());
            st_b.pop();
        }
        int next_j,cnt=0;
        bool sol=true;
        if(w_v.size()==2){
            for(int j=0;j<b_v.size();j++){
                next_j=(j+1)%b_v.size();
                if(line_cross(w_v[0],w_v[1],b_v[j],b_v[next_j]))
                    sol=false;
            }
        }
        if(b_v.size()==2){
            for(int j=0;j<w_v.size();j++){
                next_j=(j+1)%w_v.size();
                if(line_cross(b_v[0],b_v[1],w_v[j],w_v[next_j]))
                    sol=false;
            }
        }

        for(int i=0;i<w_v.size();i++){
            cnt=0;
            for(int j=0;j<b_v.size();j++){
                next_j=(j+1)%b_v.size();
                ll tmp =ccw(b_v[j],b_v[next_j],w_v[i]);
                if(tmp<0)
                    cnt++;
                else if(tmp ==0){
                    if(b_v[j]<b_v[next_j]&& b_v[j]<w_v[i] && w_v[i]<b_v[next_j])
                        cnt++;
                    else if(b_v[next_j]<b_v[j]&& b_v[next_j]<w_v[i] && w_v[i]<b_v[j])
                        cnt++;
                }
            }
            if(cnt==b_v.size())
                sol=false;
        }
        for(int i=0;i<b_v.size();i++){
            cnt=0;
            for(int j=0;j<w_v.size();j++){
                next_j=(j+1)%w_v.size();
                ll tmp =ccw(w_v[j],w_v[next_j],b_v[i]);
                if(tmp<0)
                    cnt++;
                else if(tmp ==0){
                    if(w_v[j]<w_v[next_j]&& w_v[j]<b_v[i] && b_v[i]<w_v[next_j])
                        cnt++;
                    else if(w_v[next_j]<w_v[j]&& w_v[next_j]<b_v[i] && b_v[i]<w_v[j])
                        cnt++;
                }
            }
            if(cnt==w_v.size())
                sol=false;
        }
        if(sol)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    
    }
    int buho(vec& v1,vec& v2,vec& v3){
        ll tmp =ccw(v1,v2,v3);
        if(tmp>0)
            return 1;
        else if(tmp==0)
            return 0;
        else if(tmp<0)
            return -1;
    }
    bool line_cross(vec line1_s,vec line1_e,vec line2_s,vec line2_e){
        int tmp1 = buho(line1_s,line1_e,line2_s)*buho(line1_s,line1_e,line2_e);
        int tmp2 = buho(line2_s,line2_e,line1_s)*buho(line2_s,line2_e,line1_e);
        if(tmp1==0 && tmp2 ==0){
            if(line1_e<line1_s)
                swap(line1_s,line1_e);
            if(line2_e<line2_s)
                swap(line2_s,line2_e);
            if((line1_s<line2_e||line1_s==line2_e) && (line2_s<line1_e||line2_s==line1_e))
                return true;
            else
                return false;
        }
        else if(tmp1<=0 &&tmp2 <=0)
            return true;
        else
            return false;
    }
    
};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        dot_separate ds;
        ds.convexhull();
    }

    return 0;
}