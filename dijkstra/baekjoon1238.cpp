#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct compare{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return a.second>b.second;
    }
};
class floyd{
private:
    vector<vector<int>> dp;
    vector<vector<pair<int,int>>> path;
    int N,M,X;
public:
    floyd(){
        std::cin >> N >> M >> X;
        dp.resize(N+1,vector<int>(N+1,N*100));
        path.resize(N+1);
        set_val();
    }
    void set_val(){
        int a,b,dis;
        for(int i=0;i<M;i++){
            std::cin >> a >> b >> dis;
            path[a].push_back({b,dis});
        }
    }
    
    void dijkstra(int START){
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        dp[START][START]=0;
        pq.push({START,0});
        pair<int,int> cur,next;
        while(!pq.empty()){
            cur=pq.top();
            pq.pop();
            if(dp[START][cur.first]<cur.second)
                continue;
            for(int i=0;i<path[cur.first].size();i++){
                next=path[cur.first][i];
                if(dp[START][next.first]>next.second+cur.second){
                    dp[START][next.first]=next.second+cur.second;
                    pq.push({next.first,dp[START][next.first]});
                }
            }
        }
    }
    void floyd_warshall(){
        int sol=0;
        dijkstra(X);
        for(int i=1;i<=N;i++){
            if(i==X)
                continue;
            dijkstra(i);
            sol=max(sol,dp[i][X]+dp[X][i]);
        }
        std::cout << sol ;
    }


};
int main(){
    floyd fl;
    fl.floyd_warshall();

    return 0;
}