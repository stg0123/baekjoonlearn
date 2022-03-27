#include <iostream>
#include <vector>
using namespace std;
class hello{
private:
    vector<vector<int>> dp;
    vector<pair<int,int>> val;
    int N;
public:
    hello(){
        std::cin >> N;
        dp.resize(N+1,vector<int>(101,-1));
        val.resize(N+1);
        set_val();
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >>val[i].first;
        for(int i=1;i<=N;i++)
            std::cin >>val[i].second;
    }
    int DP(int n,int cost){
        if(n==0)
            return 0;
        if(dp[n][cost]!=-1)
            return dp[n][cost];
        dp[n][cost]=DP(n-1,cost);
        if(cost>val[n].first)
            dp[n][cost]=max(dp[n][cost],DP(n-1,cost-val[n].first)+val[n].second);
        return dp[n][cost];
    }
    void start_dp(){
        std::cout << DP(N,100);
    }

};
int main(){
    hello he;
    he.start_dp();
    return 0;
}