#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000007
struct node{
    vector<int> edge;
};
class path_num{
private:
    vector<node> map;
    vector<vector<long long>> dp;
    int N,COST;
public:
    path_num(){
        std::cin >> COST;
        N=8;
        map.resize(N+1);
        dp.resize(N+1);
        for(int i=1;i<=N;i++)
            dp[i].resize(COST+1,-1);
        dp[1][0]=1;
        set_connect();
    };
    void set_connect(){
        map[1].edge.push_back(2);
        map[1].edge.push_back(3);
        
        map[2].edge.push_back(1);
        map[2].edge.push_back(3);
        map[2].edge.push_back(4);
        
        map[3].edge.push_back(1);
        map[3].edge.push_back(2);
        map[3].edge.push_back(4);
        map[3].edge.push_back(5);
        
        map[4].edge.push_back(2);
        map[4].edge.push_back(3);
        map[4].edge.push_back(5);
        map[4].edge.push_back(6);

        map[5].edge.push_back(3);
        map[5].edge.push_back(4);
        map[5].edge.push_back(6);
        map[5].edge.push_back(7);
        
        map[6].edge.push_back(4);
        map[6].edge.push_back(5);
        map[6].edge.push_back(8);
        
        map[7].edge.push_back(5);
        map[7].edge.push_back(8);
        
        map[8].edge.push_back(6);
        map[8].edge.push_back(7);
    }

    long long DP(int idx,int cost){
        if(cost<0)
            return 0;
        if(dp[idx][cost]!=-1)
            return dp[idx][cost];
        long long sum=0;
        for(int i=0;i<map[idx].edge.size();i++){
            sum =(sum+DP(map[idx].edge[i],cost-1))%INF;
        }
        dp[idx][cost]=sum%INF;
        return dp[idx][cost];
    }

    void find(){
        std::cout << DP(1,COST)<<'\n';
    }

};
int main(){
    path_num p;
    p.find();

    return 0;
}