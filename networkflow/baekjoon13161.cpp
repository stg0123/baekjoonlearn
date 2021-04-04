#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
struct _node{
    int capacity;
    int flow;
};
class dinic_basic{
private:
    vector<vector<_node>> cf;
    vector<vector<int>> path;
    vector<int> level,work;
    int N;
    int S,T;
public:
    dinic_basic(){
        std::cin>> N;
        cf.resize(N+2,vector<_node>(N+2));
        path.resize(N+2);
        level.resize(N+2);
        work.resize(N+2);
        S=0,T=N+1;
        set_val();
    }
    void set_val(){
        int team;
        for(int i=1;i<=N;i++){
            std::cin >>team;
            if(team==1){
                cf[0][i].capacity=INF;
                path[0].push_back(i);
                path[i].push_back(0);
            }
            else if(team==2){
                cf[i][N+1].capacity=INF;
                path[i].push_back(N+1);
                path[N+1].push_back(i);
            }        
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                std::cin >> cf[i][j].capacity;
                if(i!=j)
                    path[i].push_back(j);
            }
        }
    }
    bool bfs(){
        fill(level.begin(),level.end(),-1);
        queue<int> q;
        q.push(S);
        level[S]=0;
        int cur;
        while(!q.empty()){
            cur=q.front();
            q.pop();
            for(int next : path[cur]){
                if(level[next]==-1 && cf[cur][next].capacity-cf[cur][next].flow>0){
                    level[next]=level[cur]+1;
                    q.push(next);
                }
            }
        }
        return level[T]!=-1;
    }
    int dfs(int cur,int flow){
        if(cur==T)
            return flow;
        int next,tmp;
        for(int& i=work[cur];i<path[cur].size();i++){
            next=path[cur][i];
            if(level[next]==level[cur]+1 && cf[cur][next].capacity-cf[cur][next].flow>0){
                tmp=dfs(next,min(cf[cur][next].capacity-cf[cur][next].flow,flow));
                if(tmp>0){
                    cf[cur][next].flow+=tmp;
                    cf[next][cur].flow-=tmp;
                    return tmp;
                }
            }
        }
        return 0;
    }
    void dinic(){
        int sol=0;
        while(bfs()){
            fill(work.begin(),work.end(),0);
            while(1){
                int flow = dfs(S,INF);
                if(flow)
                    sol+=flow;
                else
                    break;
            }
        }
        std::cout << sol <<'\n';
        vector<bool> visit(N+2,false);
        visit[S]=true;
        queue<int> q;
        q.push(S);
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int next : path[cur]){
                if(!visit[next] && cf[cur][next].capacity-cf[cur][next].flow>0){
                    visit[next]=true;
                    q.push(next);
                }
            }
        }
        for(int i=1;i<=N;i++){
            if(visit[i])
                std::cout << i << ' ';
        }
        std::cout << '\n';
        for(int i=1;i<=N;i++){
            if(!visit[i])
                std::cout << i << ' ';
        }
        std::cout <<'\n';
    }


};
int main(){
    dinic_basic db;
    db.dinic();
    return 0;
}
