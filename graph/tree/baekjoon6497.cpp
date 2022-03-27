#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct _node{
    int a,b,dis;
};
bool compare(_node& a,_node& b){
    return a.dis<b.dis;  
};
class MST{
private:
    vector<_node> path;
    vector<int> parent;
    int N,M;
    int sum=0;
public:
    MST(int n,int m):N(n),M(m){
        parent.resize(N,-1);
        set_val();
    }
    void set_val(){
        int a,b,dis;
        for(int i=0;i<M;i++){
            std::cin >> a >> b>>dis;
            path.push_back({a,b,dis});
            sum+=dis;
        }
        sort(path.begin(),path.end(),compare);
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
    void cruscal(){
        int sol=0;
        for(int i=0;i<path.size();i++){
            if(merge(path[i].a,path[i].b))
                sol+=path[i].dis;
        }
        std::cout << sum-sol<<'\n';
    }
};
int main(){
    int n,m;
    while(1){
        std::cin >> n >> m;
        if(n==0&&m==0)
            break;
        MST mst(n,m);
        mst.cruscal();
    }
    return 0;
}