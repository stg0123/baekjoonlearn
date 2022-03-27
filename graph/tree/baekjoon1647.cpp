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
    vector<int> parent;
    vector<_node> path;
    int N,M;
public:
    MST(){
        std::cin >> N >> M;
        parent.resize(N+1,-1);
        set_val();
    }
    void set_val(){
        int a,b,dis;
        for(int i=0;i<M;i++){
            std::cin >> a >> b >> dis;
            path.push_back({a,b,dis});
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
        int sol=0,max_dis=0;
        for(int i=0;i<path.size();i++){
            if(merge(path[i].a,path[i].b)){
                sol+=path[i].dis;
                max_dis=max(max_dis,path[i].dis);
            }
        }
        std::cout << sol-max_dis ;

    }

};
int main(){
    MST m;
    m.cruscal();
    return 0;
}