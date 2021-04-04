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
class min_cost{
private:
    vector<vector<pair<int,int>>> map;
    vector<node> dp;
    int SIZE;
public:
    min_cost(){
        std::cin >> SIZE;
        map.resize(SIZE+1);
        dp.resize(SIZE+1,{INF,});
        set_connect();
    }
    void set_connect(){
        int n;
        std::cin >> n;
        int a,b,dis;
        for(int i=0;i<n;i++){
            std::cin >> a >> b>> dis;
            map[a].push_back({b,dis});
        }
    }

    void dijkstra(){
        int START,END;
        std::cin >> START>>END;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        dp[START].min_dis=0;
        dp[START].path.push_back(START);
        pq.push({START,0});
        int cur,c_dis;
        pair<int,int> tmp;
        while(!pq.empty()){
            cur=pq.top().first;
            c_dis=pq.top().second;
            pq.pop();
            if(dp[cur].min_dis<c_dis)
                continue ;
                
            for(int i=0;i<map[cur].size();i++){
                tmp=map[cur][i];
                if(dp[tmp.first].min_dis>c_dis+tmp.second){
                    dp[tmp.first].min_dis=c_dis+tmp.second;
                    dp[tmp.first].path=dp[cur].path;
                    dp[tmp.first].path.push_back(tmp.first);
                    pq.push({tmp.first,c_dis+tmp.second});
                }
            }
        }

        std::cout << dp[END].min_dis << '\n';
        std::cout << dp[END].path.size() << '\n';
        for(int i=0;i<dp[END].path.size();i++){
            std::cout << dp[END].path[i]<<' ';
        }


    }

};
int main(){
    min_cost mi;
    mi.dijkstra();
    return 0;
}