#include <iostream>
#include <vector>
using namespace std;
class coin{
private:
    vector<vector<int>> dp;
    vector<int> val;
    int N,COST;
public:
    coin(){
        std::cin >> N;
        val.resize(N+1);
        set_val();
        dp.resize(N+1,vector<int>(COST+1,-1));
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> val[i];
        std::cin >> COST;
    }
    int DP(int n,int cost){
        if(cost==0)
            return 1;
        if(n==0)
            return 0;
        if(dp[n][cost]!=-1)
            return dp[n][cost];
        dp[n][cost]=DP(n-1,cost);
        if(cost>=val[n])
            dp[n][cost]+=DP(n,cost-val[n]);
        return dp[n][cost];

    }
    void start_dp(){
        std::cout << DP(N,COST) <<'\n';

    }

};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        coin c;
        c.start_dp();
    }
    return 0;
}