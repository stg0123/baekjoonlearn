#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 100000000
struct node{
    int min_dis;
    vector<int> path;
};
struct compare{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return a.second>b.second;
    }
};
class floid{
private:
    vector<vector<pair<int,int>>> map;
    vector<vector<node>> dp;
    int SIZE;
public:
    floid(){
        std::cin >> SIZE;
        map.resize(SIZE+1);
        dp.resize(SIZE+1);
        set_connect();
    }
    void set_connect(){
        int n;
        std::cin >> n;
        int a,b,dis;
        for(int i=0;i<n;i++){
            std::cin >> a>>b>>dis;
            map[a].push_back({b,dis});
        }
    }

    void dijkstra(int START){
        dp[START].resize(SIZE+1,{INF,});
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        dp[START][START].min_dis=0;
        dp[START][START].path.push_back(START);
        pq.push({START,0});
        int cur,c_dis;
        pair<int,int> tmp;
        while(!pq.empty()){
            cur=pq.top().first;
            c_dis=pq.top().second;
            pq.pop();
            if(dp[START][cur].min_dis<c_dis)
                continue;
            for(int i=0;i<map[cur].size();i++){
                tmp=map[cur][i];
                if(dp[START][tmp.first].min_dis>c_dis+tmp.second){
                    dp[START][tmp.first].min_dis=c_dis+tmp.second;
                    dp[START][tmp.first].path=dp[START][cur].path;
                    dp[START][tmp.first].path.push_back(tmp.first);
                    pq.push({tmp.first,c_dis+tmp.second});
                }
            }
        }
    }
    void print_dp(){
        for(int i=1;i<=SIZE;i++){
            for(int j=1;j<=SIZE;j++){
                if(dp[i][j].min_dis==INF)
                    std::cout << 0 << ' ';
                else
                    std::cout << dp[i][j].min_dis << ' ';
            }
            std::cout << '\n';
        }
    }
    void print_path(){
        for(int i=1;i<=SIZE;i++){
            for(int j=1;j<=SIZE;j++){
                if(i==j)
                    std::cout << 0;
                else{
                    std::cout << dp[i][j].path.size()<<' ';
                    for(int l=0;l<dp[i][j].path.size();l++)
                        std::cout << dp[i][j].path[l] << ' ';
                }
                std::cout << '\n';
            }
        }
    }

    void start_floid(){
        for(int i=1;i<=SIZE;i++)
            dijkstra(i);
        print_dp();
        print_path();
    }


};
int main(){
    floid fl;
    fl.start_floid();

    return 0;
}