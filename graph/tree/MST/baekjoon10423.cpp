#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct _node{
    int x,y,dis;
};
bool compare(_node& a,_node& b){
    return a.dis <b.dis;
};
class electric{
private:
    vector<int> parent;
    vector<_node> path;
    int N,M,K;
public:
    electric(){
        std::cin >> N >> M >> K;
        parent.resize(N+1,-1);
        set_val();
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
    void set_val(){
        int a,b,dis;
        std::cin >> a;
        for(int i=1;i<K;i++){
            std::cin >> b;
            merge(a,b);
        }
        for(int i=0;i<M;i++){
            std::cin >>a >> b>> dis;
            path.push_back({a,b,dis});
        }
        sort(path.begin(),path.end(),compare);
    }  
    void cruscal(){
        int sol=0;
        for(int i=0;i<path.size();i++){
            if(merge(path[i].x,path[i].y))
                sol+=path[i].dis;
        }
        std::cout << sol <<'\n';
    }

    
};
int main(){
    electric el;
    el.cruscal();
    return 0;
}