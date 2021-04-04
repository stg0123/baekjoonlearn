#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct _node{
    int x,y,dis;
};
bool compare(_node& a,_node& b){
    return a.dis<b.dis;
};
struct compare_pq{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return a.second>b.second;
    };
};
class network_cruscal{
private:
    vector<int> parent;
    vector<_node> path; 
    int N,M;
public:
    network_cruscal(){
        std::cin >> N>> M;
        parent.resize(N+1,-1);
        set_val();
    }
    void set_val(){
        int a,b,dis;
        for(int i=0;i<M;i++){
            std::cin >> a>> b>> dis;
            path.push_back({a,b,dis});
        }
        sort(path.begin(),path.end(),compare);
    }
    int find(int n){
        if(parent[n]==-1)
            return n;
        return parent[n]=find(parent[n]);
    }
    int merge(int a,int b){
        int p_a =find(a);
        int p_b =find(b);
        if(p_a==p_b)
            return 0;
        parent[p_b]=p_a;
        return 1;
    }
    void cruscal(){
        int sol=0,num=0;
        for(int i=0;i<path.size();i++){
            if(merge(path[i].x,path[i].y)){
                sol+=path[i].dis;
                num++;
            }
            if(num==N-1)
                break;
        }
        std::cout << sol <<'\n';
    }
};
class network_prim{
private:
    vector<vector<pair<int,int>>> path;
    int N,M;
public:
    network_prim(){
        std::cin >> N >> M;
        path.resize(N+1);
        set_val();
    }
    void set_val(){
        int a,b,dis;
        for(int i=0;i<M;i++){
            std::cin >>a >>b >>dis;
            path[a].push_back({b,dis});
            path[b].push_back({a,dis});
        }
    }
    void prim(){
        int start=1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare_pq> pq;
        pq.push({start,0});
        vector<bool> visit(N+1,false);
        pair<int,int> cur,next;
        int sol=0;
        while(!pq.empty()){
            cur =pq.top();
            pq.pop();
            if(visit[cur.first])
                continue;
            visit[cur.first]=true;
            sol+=cur.second;
            for(int i=0;i<path[cur.first].size();i++){
                next=path[cur.first][i];
                if(!visit[next.first])
                    pq.push({next.first,next.second});
            }
        }
        std::cout << sol;
    }


};
int main(){
    // network_cruscal nc;
    // nc.cruscal();
    network_prim np;
    np.prim();
    return 0;
}