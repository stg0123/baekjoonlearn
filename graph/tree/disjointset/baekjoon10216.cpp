#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct _node{
    int x,y,r;
};
class CCG{
private:
    vector<int> parent;
    vector<_node> val;
    int N;
    int sol;
public:
    CCG(){
        std::cin >> N;
        sol=N;
        parent.resize(N,-1);
        set_val();
    }
    void set_val(){
        int x,y,r;
        for(int i=0;i<N;i++){
            std::cin >> x>> y>>r;
            val.push_back({x,y,r});
        }
    }
    int find(int n){
        if(parent[n]==-1)
            return n;
        return parent[n]=find(parent[n]);
    }
    void merge(int a,int b){
        int p_a=find(a);
        int p_b=find(b);
        if(p_a==p_b)
            return ;
        parent[p_b]=p_a;
        sol--;
    }
    bool meet(int a,int b){
        int dx =val[a].x-val[b].x;
        int dy =val[a].y-val[b].y;
        int dr =val[a].r+val[b].r;
        if(dx*dx+dy*dy>dr*dr)
            return false;
        return true;
        
    }
    void find_sol(){
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(meet(i,j))
                    merge(i,j);
            }
        }
        std::cout << sol<<'\n';
    }
};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        CCG cc;
        cc.find_sol();
    }
    return 0;
}