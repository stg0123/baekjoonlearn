#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
struct _node{
    int parent;
    int x,y;
};
struct compare{
    bool operator()(pair<int,double>& a,pair<int,double>& b){
        return a.second>b.second;
    }

};
class unionfind_prim{
private:
    vector<_node> node;
    int N,M;
public:
    unionfind_prim(){
        std::cin >> N >> M;
        node.resize(N+1,{-1,});
        set_val();
    }
    int find(int n){
        if(node[n].parent<0)
            return n;
        return node[n].parent = find(node[n].parent);
    }
    bool merge(int a,int b){
        int p_a=find(a);
        int p_b=find(b);
        if(p_a==p_b)
            return false;
        node[p_b].parent=p_a;
        return true;
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> node[i].x >> node[i].y;
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a >> b;
            merge(a,b);
        }
    }
    double distance(int a,int b){
        if(find(a)==find(b))
            return 0;
        double dx=node[a].x-node[b].x;
        double dy=node[a].y-node[b].y;
        return sqrt(dx*dx+dy*dy);
    }


    void prim(){
        int start=1;
        priority_queue<pair<int,double>,vector<pair<int,double>>,compare> pq;
        vector<bool> visit(N+1,false);
        pq.push({start,0});
        int cur;
        double c_dis,solution=0,tmp;
        while(!pq.empty()){
            cur =pq.top().first;
            c_dis = pq.top().second;
            pq.pop();
            if(visit[cur]==true)
                continue;
            visit[cur]=true;
            solution+=c_dis;
            for(int i=1;i<=N;i++){
                if(!visit[i]){
                    tmp=distance(cur,i);
                    pq.push({i,tmp});
                }
            }
        }
        printf("%.2lf",solution);
    }
};
int main(){
    unionfind_prim unifr;
    unifr.prim();

    return 0;    
}