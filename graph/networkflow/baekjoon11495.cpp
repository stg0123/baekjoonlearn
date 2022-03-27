#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
struct _node{
    int capacity;
    int flow;
};
class make0_dinic{
private:
    vector<vector<_node>> cf;
    vector<vector<int>> path;
    vector<int> next_table,level;
    int N,M;
    int S,T;
    int sum=0;
public:
    make0_dinic(){
        std::cin >> N >> M;
        cf.resize(N*M+2,vector<_node>(N*M+2));
        path.resize(N*M+2,vector<int>(N*M+2));
        next_table.resize(N*M+2);
        level.resize(N*M+2);
        S=0,T=N*M+1;
        set_val();
    }
    void set_val(){
        int idx,tmp,nx,ny,next;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                std::cin >> tmp;
                sum+=tmp;
                idx =i*M+j+1;
                if((i+j)%2==0){
                    cf[0][idx].capacity=tmp;
                    path[0].push_back(idx);
                    path[idx].push_back(0);
                    for(int l=0;l<4;l++){
                        nx=i+dx[l],ny=j+dy[l];
                        if(nx>=0 && nx<N && ny>=0 && ny<M){
                            next=nx*M+ny+1;
                            cf[idx][next].capacity=INF;
                            path[idx].push_back(next);
                            path[next].push_back(idx);
                        }
                    }
                }
                else{
                    cf[idx][N*M+1].capacity=tmp;
                    path[idx].push_back(N*M+1);
                    path[N*M+1].push_back(idx);
                }
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
            cur =q.front();
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
        int next,cp;
        for(int& i=next_table[cur];i<path[cur].size();i++){
            next=path[cur][i];
            if(level[next]==level[cur]+1 && cf[cur][next].capacity-cf[cur][next].flow>0){
                cp= dfs(next,min(cf[cur][next].capacity-cf[cur][next].flow,flow));
                if(cp>0){
                    cf[cur][next].flow+=cp;
                    cf[next][cur].flow-=cp;
                    return cp;
                }
            }
        }
        return 0;
    }

    void dinic(){
        int sol=0;
        while(bfs()){
            fill(next_table.begin(),next_table.end(),0);
            while(1){
                int flow = dfs(S,INF);
                if(flow)
                    sol+=flow;
                else 
                    break;
            }
        }
        std::cout << sum-sol<<'\n';
    }

};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        make0_dinic md;
        md.dinic();
    }
    return 0;
}