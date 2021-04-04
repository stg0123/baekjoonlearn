#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000000
using namespace std;
struct compare{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return a.second>b.second;
    }
};
class k_dijkstra{
private:
    vector<vector<pair<int,int>>> path;
    vector<priority_queue<int>> dp;
    int N,M,K;
public:
    k_dijkstra(){
        std::cin >> N >> M >> K;
        path.resize(N+1);
        dp.resize(N+1);
        set_val();
    }
    void set_val(){
        int a,b,dis;
        for(int i=0;i<M;i++){
            std::cin >> a >> b >> dis;
            path[a].push_back({b,dis});
        }
    }
    void dijkstra(){
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        dp[1].push(0);
        pq.push({1,0});
        pair<int,int> cur,next;
        int tmp;
        while(!pq.empty()){
            cur=pq.top();
            pq.pop();
            for(int i=0;i<path[cur.first].size();i++){
                next=path[cur.first][i];
                tmp =cur.second+next.second;
                if(dp[next.first].size()<K){
                    dp[next.first].push(tmp);
                    pq.push({next.first,tmp});
                }
                else if(dp[next.first].top()>tmp){
                    dp[next.first].pop();
                    dp[next.first].push(tmp);
                    pq.push({next.first,tmp});
                }
            }
        }
        for(int i=1;i<=N;i++){
            if(dp[i].size()!=K)
                std::cout << -1 <<'\n';
            else
                std::cout << dp[i].top() <<'\n';
        }
    }

};
int main(){
    k_dijkstra kd;
    kd.dijkstra();

    return 0;
}