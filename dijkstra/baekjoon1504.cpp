#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 100000000
struct node{
    int min_dis;
    vector<pair<int,int>> edge_dis;

};
template<typename T>
struct compare{
    bool operator()(T& A,T& B){
        return A.second > B.second;
    }

};

class dijkstra{
private:
    vector<node> dp;
    int edge_num,line_num;
public:
    dijkstra(int n,int m):edge_num(n),line_num(m){
        dp.resize(edge_num+1);
    }
    void set_connect(){
        int a,b,dis;
        for(int i=0;i<line_num;i++){
            std::cin >> a>> b>> dis;
            dp[a].edge_dis.push_back({b,dis});
            dp[b].edge_dis.push_back({a,dis});
        }
    }

    vector<node> cal_dijkstra(int START){
        for(int i=0;i<=edge_num;i++)
            dp[i].min_dis=INF;
       
        priority_queue<pair<int,int>, vector<pair<int,int>>,compare<pair<int,int>> > pq;
        vector<bool> visit(edge_num+1,false);
        dp[START].min_dis=0;
        pq.push({START,0});
        int cur,dis,tmp;
        while(!pq.empty()){
            cur=pq.top().first;
            dis=pq.top().second;
            pq.pop();
            if(visit[cur]==true)
                continue;
            visit[cur]=true;
            for(int i=0;i<dp[cur].edge_dis.size();i++){
                tmp=dp[cur].edge_dis[i].first;
                if(visit[tmp]==false&&dp[tmp].min_dis>dis+dp[cur].edge_dis[i].second){
                    dp[tmp].min_dis=dis+dp[cur].edge_dis[i].second;
                    pq.push({tmp,dp[tmp].min_dis});
                }
            }
        }                

        return dp;

    }

};
int main(){
    int n,m;
    int loc1,loc2;
    vector<node> tmp1,tmp2,tmp3;
    std::cin >> n>>m;
    dijkstra di(n,m);
    di.set_connect();
    std::cin >> loc1>>loc2;
    tmp1=di.cal_dijkstra(1);
    tmp2=di.cal_dijkstra(loc1);
    tmp3=di.cal_dijkstra(loc2);
    long long ans =min(tmp1[loc1].min_dis+tmp2[loc2].min_dis+tmp3[n].min_dis,tmp1[loc2].min_dis+tmp3[loc1].min_dis+tmp2[n].min_dis);
    if(ans >= INF)
        std::cout << -1 << '\n';
    else
        std::cout << ans << '\n';
    return 0;
}