#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node{
    int min_val;
    vector<pair<int,int>> edge_dis;
};
class dijkstra{
private:
    vector<node> dp;
    vector<int> edge;
    int N,line,START;
    int INF;
public:
    dijkstra(){
        std::cin >> N >> line >> START;
        INF=N*10;
        dp.resize(N+1,{INF,});
        dp[START].min_val=0;
        for(int i=1;i<=N;i++)
            edge.push_back(i);
        
    }
    void set_connect(){
        int a,b,dis;
        for(int i=0;i<line;i++){
            std::cin >> a>>b>>dis;
            dp[a].edge_dis.push_back({b,dis});
        }
    }
    void cal(){
        int i=START,min_,min_idx;
        pair<int,int> tmp;
        edge.erase(edge.begin()+START-1);
        while(1){
            for(int j=0;j<dp[i].edge_dis.size();j++){
                tmp = dp[i].edge_dis[j];
                dp[tmp.first].min_val= min(dp[i].min_val+tmp.second,dp[tmp.first].min_val);
            }
            min_=INF+1;
            if(edge.empty())
                break;
            for(int j=0;j<edge.size();j++){
                if(min_>dp[edge[j]].min_val){
                    min_=dp[edge[j]].min_val;
                    min_idx=j;
                }
            }
            i=edge[min_idx];
            edge.erase(edge.begin()+min_idx);
        }

        for(int i=1;i<=N;i++){
            if(dp[i].min_val== INF)
                std::cout << "INF\n";
            else
                std::cout << dp[i].min_val<<'\n';
        }

    }
};
int main(){
    dijkstra di;
    di.set_connect();
    di.cal();

    return 0;
}