#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
class node{
    public:
        int data;
        vector<node *> edge;
};
void connect(vector<node>& nd, int M){
    for(int i=0;i<M;i++){
        int a,b;
        std::cin >> a>>b;
        nd[a].data=a;
        nd[b].data=b;

        nd[a].edge.push_back(&nd[b]);
        nd[b].edge.push_back(&nd[a]);
    }

};
void dfs(vector<node>& nd,int n,vector<bool>& visit){
    if(visit[n]==true)
        return ;
    
    visit[n]=true;
    std::cout << n << ' ';
    if(nd[n].edge.size()==0)
        return ;

    for(int i=0;i<nd[n].edge.size();i++){
        dfs(nd,nd[n].edge[i]->data,visit);
    }
    return ;
};

void bfs(vector<node>& nd,int n,vector<bool>& visit){
    if(nd[n].edge.size()==0){
        std::cout << n;
        return;
    }
    queue<node *> q;
    q.push(&nd[n]);
    while(!q.empty()){
        node *tmp=q.front();
        if(visit[tmp->data]==true)
            q.pop();
        else{
            visit[tmp->data]=true;
            std::cout << tmp->data << ' ';
            for(int i=0;i<tmp->edge.size();i++){
                q.push(tmp->edge[i]);
            }
            q.pop();
        }
    }
    return ;

}

bool compare(node *a,node *b){
    return a->data<b->data;
}
int main(){
    vector<node> nd;
    vector<bool> visit;
    int N,M,V;
    std::cin >> N >> M >> V;
    nd.resize(N+1);
    visit.resize(N+1,false);
    connect(nd,M);
    
    for(int i=1;i<=N;i++)
        sort(nd[i].edge.begin(),nd[i].edge.end(),compare);

    dfs(nd,V,visit);
    visit.clear();
    visit.resize(N+1,false);
    std::cout << '\n';
    bfs(nd,V,visit);


    return 0;
}