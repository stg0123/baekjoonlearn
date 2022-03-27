#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct _node{
    char color;
    int x,y;
};
bool redfirst_compare(_node& a,_node& b){
    return a.color>b.color;
};
bool bluefirst_compare(_node& a,_node& b){
    return a.color<b.color;
};
class RBST{
private:
    vector<int> parent;
    vector<_node> path;
    int N,M,K;
public:
    RBST(int n,int m,int k):N(n),M(m),K(k){
        parent.resize(N+1);
        set_val();
    }
    void set_val(){
        char ch;
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> ch >> a>> b;
            path.push_back({ch,a,b});
        }
    }
    int find(int n){
        if(parent[n]==-1)
            return n;
        return parent[n]=find(parent[n]);
    }
    bool merge(int a,int b){
        int p_a=find(a);
        int p_b=find(b);
        if(p_a==p_b)
            return false;
        parent[p_b]=p_a;
        return true;
    }
    int cruscal(){
        int sol=0,cnt=0;
        fill(parent.begin(),parent.end(),-1);
        for(int i=0;i<path.size();i++){
            if(merge(path[i].x,path[i].y)){
                if(path[i].color=='B')
                    sol++;
                cnt++;
            }
            if(cnt==N-1)
                break;
        }
        return sol;
    }
    void find_sol(){
        int tmp1,tmp2;
        sort(path.begin(),path.end(),redfirst_compare);
        tmp1 =cruscal();
        sort(path.begin(),path.end(),bluefirst_compare);
        tmp2=cruscal();
        if(tmp1<= K && K<=tmp2)
            std::cout << 1 <<'\n';
        else
            std::cout << 0 <<'\n';
    }


};
int main(){
    int n,m,k;
    while(1){
        std::cin >> n >> m >> k;
        if(n==0 &&m==0 &&k==0)
            break;
        RBST st(n,m,k);
        st.find_sol();
    }
    return 0;
}