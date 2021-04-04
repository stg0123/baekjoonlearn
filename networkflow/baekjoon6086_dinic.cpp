#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
struct _node{
    int capacity;
    int flow;
};
int ctoi(char ch){
    return ch<='Z' ? ch-'A' : ch-'a'+26;
};
class dinic_basic{
private:
    vector<vector<_node>> cf;
    vector<vector<int>> path;
    vector<int> work,level;
    int N;
    int S,T;
public:
    dinic_basic(){
        std::cin >> N;
        cf.resize(52,vector<_node>(52));
        path.resize(52);
        level.resize(52);
        work.resize(52);
        S=ctoi('A');
        T=ctoi('Z');
        set_connect();
    }

    void set_connect(){
        char a,b;
        int c,ai,bi;
        for(int i=0;i<N;i++){
            std::cin >> a >> b >> c;
            ai=ctoi(a);
            bi=ctoi(b);
            path[ai].push_back(bi);
            path[bi].push_back(ai);
            cf[ai][bi].capacity+=c;
            cf[bi][ai].capacity+=c;
        }
    }
    bool bfs(){
        fill(level.begin(),level.end(),-1);
        level[S]=0;
        queue<int> q;
        q.push(S);
        int cur,next;
        while(!q.empty()){
            cur= q.front();
            q.pop();
            for(int i=0;i<path[cur].size();i++){
                next=path[cur][i];
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
        for(int& i =work[cur]; i<path[cur].size();i++){
            next=path[cur][i];
            if(level[next]==level[cur]+1 && cf[cur][next].capacity-cf[cur][next].flow>0){
                tmp =dfs(next,min(cf[cur][next].capacity-cf[cur][next].flow,flow));
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
                int flow =dfs(S,INF);
                if(flow==0)
                    break;
                sol +=flow;
            }
        }
        std::cout << sol;
    }

};
int main(){
    dinic_basic db;
    db.dinic();
    return 0;
}