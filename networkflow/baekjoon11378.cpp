#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
struct _node{
    int capacity;
    int flow;
};
class work4{
private:
    vector<vector<_node>> cf;
    vector<vector<int>> path;
    vector<int> prev;
    int N,M,K;
public:
    work4(){
        std::cin >> N >> M >> K;
        cf.resize(N+M+3,vector<_node>(N+M+3)); 
        path.resize(N+M+3);
        prev.resize(N+M+3);
        set_connect();
    }  
    void set_connect(){
        int n,a;
        for(int i=1;i<=N;i++){
            path[0].push_back(i);
            path[i].push_back(0);
            path[N+M+1].push_back(i);
            path[i].push_back(N+M+1);
            cf[0][i].capacity+=1;
            cf[N+M+1][i].capacity+=K;
            std::cin >> n;
            for(int j=0;j<n;j++){
                std::cin >>a ;
                path[i].push_back(a+N);
                path[a+N].push_back(i);
                cf[i][a+N].capacity+=1;
            }
        }
        for(int i=1;i<=M;i++){
            path[i+N].push_back(N+M+2);
            path[N+M+2].push_back(i+N);
            cf[i+N][N+M+2].capacity+=1;
        }
        path[0].push_back(N+M+1);
        path[N+M+1].push_back(0);
        cf[0][N+M+1].capacity+=K;
    }
    void edmond_karp(int sorce,int sink){
        int cur,next;
        int result=0;
        while(1){
            fill(prev.begin(),prev.end(),-1);
            queue<int> q;
            q.push(sorce);
            prev[sorce]=sorce;
            while(!q.empty()&& prev[sink]==-1){
                cur=q.front();
                q.pop();
                for(int i=0;i<path[cur].size();i++){
                    next =path[cur][i];
                    if(cf[cur][next].capacity-cf[cur][next].flow>0 && prev[next]==-1){
                        q.push(next);
                        prev[next]=cur;
                        if(next==sink)
                            break;
                    }
                }
            }
            if(prev[sink]==-1)
                break;
            int flow =INF;
            for(int i=sink;i!=sorce;i=prev[i])
                flow=min(flow,cf[prev[i]][i].capacity-cf[prev[i]][i].flow);
            
            for(int i=sink;i!=sorce;i=prev[i]){
                cf[prev[i]][i].flow+=flow;
                cf[i][prev[i]].flow-=flow;
            }
            result+=flow;
        }
        std::cout << result;
    }
    void find_sol(){
        edmond_karp(0,M+N+2);
    }
};
int main(){
    work4 wk;
    wk.find_sol();
    return 0;
}