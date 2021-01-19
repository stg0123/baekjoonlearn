#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 100000000
struct node{
    int edge,cost,dis;
    bool operator < (const node& p)const {
        if(this->dis == p.dis)
            return this->cost > p.cost;
        else
            return this->dis > p.dis;
        
    }
};

class travel{
private:
    vector<vector<node>> map;
    vector<vector<int>> dp;
    int SIZE,MAX_COST;
public:
    travel(){
        std::cin >> SIZE >> MAX_COST;
        map.resize(SIZE+1);
        dp.resize(SIZE+1);
        for(int i=1;i<=SIZE;i++)
            dp[i].resize(MAX_COST+1,INF);
        set_connect();
    }

    void set_connect(){
        int n;
        std::cin>>n;
        int a,b,cost,dis;
        for(int i=0;i<n;i++){
            std::cin >> a >> b >> cost >> dis;
            map[a].push_back({b,cost,dis});
        }
    }
    void dijkstra(){
        int START =1;
        priority_queue<node> pq;
        pq.push({START,0,0});
        dp[START][0]=0;
        int cur,c_cost,c_dis;
        node tmp;
        while(!pq.empty()){
            cur=pq.top().edge;
            c_cost=pq.top().cost;
            c_dis=pq.top().dis;
            pq.pop();
            if(c_dis >dp[cur][c_cost])
                continue;

            for(int i=0;i<map[cur].size();i++){
                tmp=map[cur][i];
                if(c_cost+tmp.cost<=MAX_COST){
                    if(dp[tmp.edge][c_cost+tmp.cost]>c_dis+tmp.dis){
                        dp[tmp.edge][c_cost+tmp.cost]=c_dis+tmp.dis;
                        pq.push({tmp.edge,c_cost+tmp.cost,c_dis+tmp.dis});
                    }
                }
            }
        }
        int sol=INF;
        for(int i=0;i<=MAX_COST;i++){
            sol=min(sol,dp[SIZE][i]);
        }
        if(sol==INF)
            std::cout << "Poor KCM\n";
        else
            std::cout<<sol<<'\n';
    }

};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        travel tr;
        tr.dijkstra();
    }


    return 0;
}