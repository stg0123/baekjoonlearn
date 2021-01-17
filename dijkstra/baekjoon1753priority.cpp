#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node{
    int min_dis;
    vector<pair<int,int>> edge_dis;
};

struct compare{
    bool operator()(pair<int,int>& A,pair<int,int>& B){
        return A.second>B.second;
    }
};

class dijkstra{
private:
    vector<node> dp;
    vector<bool> visit;
    int SIZE,START;
    int line_num;
    int INF;
public:
    dijkstra(){
        std::cin >> SIZE >> line_num >> START;
        INF =SIZE*10;
        dp.resize(SIZE+1,{INF,});
        dp[START].min_dis=0;
        visit.resize(SIZE+1,false);

    }

    void set_connect(){
        int a,b,dis;
        for(int i=0;i<line_num;i++){
            std::cin >> a>> b>>dis;
            dp[a].edge_dis.push_back({b,dis});
        }
    }
    
    void cal_dijkstra(){
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        pq.push({START,0});
        int cur,dis,tmp;
        while(!pq.empty()){
            cur = pq.top().first;
            dis = pq.top().second;
            pq.pop();
            if(visit[cur]==true)
                continue;
            visit[cur]=true;
            for(int i=0;i<dp[cur].edge_dis.size();i++){
                tmp = dp[cur].edge_dis[i].first;
                if(visit[tmp]==false&&dp[tmp].min_dis>dis+dp[cur].edge_dis[i].second){
                    dp[tmp].min_dis=dis+dp[cur].edge_dis[i].second;
                    pq.push({tmp,dp[tmp].min_dis});
                }
            }
        }
        for(int i=1;i<=SIZE;i++){
            if(dp[i].min_dis== INF)
                std::cout << "INF\n";
            else
                std::cout << dp[i].min_dis << '\n';
        }

    }
};
int main(){
    dijkstra di;
    di.set_connect();
    di.cal_dijkstra();

    return 0;
}