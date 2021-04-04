#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
struct compare{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
            return a.second>b.second;
    }
};
class hacking{
private:
    vector<int> dp;
    vector<vector<pair<int,int>>> path;
    int N,D,C;
public:
    hacking(){
        std::cin >> N >> D >> C;
        dp.resize(N+1,INF);
        path.resize(N+1);
        set_val();
    }
    void set_val(){
        int a,b,dis;
        for(int i=0;i<D;i++){
            std::cin >> a >> b >>dis;
            path[b].push_back({a,dis});
        }
    }
    void dijkstra(){
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        pq.push({C,0});
        dp[C]=0;
        pair<int,int> cur,next;
        int max_sol=0,sol=0;
        vector<bool> visit(N+1,false);
        while(!pq.empty()){
            cur =pq.top();
            pq.pop();
            if(visit[cur.first])
                continue;
            visit[cur.first]=true;
            sol++;
            max_sol =max(max_sol,cur.second); 
            for(int i=0;i<path[cur.first].size();i++){
                next=path[cur.first][i];
                if(dp[next.first]>cur.second+next.second){
                    dp[next.first]=cur.second+next.second;
                    pq.push({next.first,dp[next.first]});
                }
            }
        }
        std::cout << sol << ' '<<max_sol<<'\n';
    }



};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        hacking hk;
        hk.dijkstra();
    }

    return 0;
}