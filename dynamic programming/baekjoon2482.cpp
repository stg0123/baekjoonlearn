#include <iostream>
#include <vector>
#define INF 1000000003
using namespace std;
class color_circle{
private:
    vector<vector<int>> dp;
    int N,M;
public:
    color_circle(){
        std::cin >>N>>M;
        dp.resize(N+1,vector<int>(M+1,-1));

    }
    void start_dp(){
        std::cout << (DP(N-3,M-1)+DP(N-1,M))%INF;
    }
    int DP(int n,int k){
        if(n<1)
            return 0;
        if(dp[n][k]!=-1)
            return dp[n][k];
        if(k==0)
            return 1;
        if(k==1)
            return n;
        dp[n][k]=(DP(n-2,k-1)+DP(n-1,k))%INF;
        return dp[n][k];
    }


};
int main(){
    color_circle cc;
    cc.start_dp();

    return 0;
}