#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
struct _node{
    int capacity;
    int flow;
};
class makemap{
private:
    vector<vector<_node>> cf;
    vector<vector<int>> path;
    vector<int> level,work;
    int N,SUM=0,MAXVAL=0;
    int S,T;
public:
    makemap(){
        std::cin >> N;
        S=0,T=N*2+1;
        cf.resize(N*2+2,vector<_node>(N*2+2));
        path.resize(N*2+2);
        level.resize(N*2+2);
        work.resize(N*2+2);
        set_connect();
    }
    void set_connect(){
        int tmp;
        for(int i=1;i<=N;i++){
            std::cin >> tmp;
            SUM+=tmp;
            MAXVAL=max(MAXVAL,tmp);
            path[S].push_back(i);
            path[i].push_back(S);
            cf[S][i].capacity=tmp;
        }
        for(int i=1;i<=N;i++){
            std::cin >> tmp;
            SUM+=tmp;
            MAXVAL=max(MAXVAL,tmp);
            path[i+N].push_back(T);
            path[T].push_back(i+N);
            cf[i+N][T].capacity=tmp;
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                path[i].push_back(j+N);
                path[j+N].push_back(i);
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
                tmp =dfs(next,min(flow,cf[cur][next].capacity-cf[cur][next].flow));
                if(tmp){
                    cf[cur][next].flow+=tmp;
                    cf[next][cur].flow-=tmp;
                    return tmp;
                }
            }
        }
        return 0;
    }
    bool dinic(int cap){
        int result=0;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                cf[i][j+N].capacity=cap;
        for(int i=0;i<2*N+2;i++)
            for(int j=0;j<2*N+2;j++)
                cf[i][j].flow=0;
        
        while(bfs()){
            fill(work.begin(),work.end(),0);
            while(1){
                int flow = dfs(S,INF);
                if(flow==0)
                    break;
                result+=flow;
            }
        }
        return result*2==SUM;
    }
    void find_sol(){
        int left=0,right=MAXVAL;
        int sol;
        while(left<=right){
            int mid=(left+right)/2;
            if(dinic(mid)){
                sol=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        std::cout << sol<<'\n';
        dinic(sol);
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++)
                std::cout << cf[i][j+N].flow <<' ';
            std::cout << '\n';
        }
    }


};
int main(){
    makemap mm;
    mm.find_sol();
    return 0;
}