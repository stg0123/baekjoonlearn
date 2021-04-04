#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int mod = 9901;
class zoo{
private:
    vector<vector<ll>> dp;
    int N;
public:
    zoo(){
        std::cin >> N;
        dp.resize(N+1,vector<ll>(3,-1));
    }
    ll DP(int n,int m){
        if(n==1)
            return 1;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(m==0)
            dp[n][m]=DP(n-1,0)+DP(n-1,1)+DP(n-1,2);
        else if(m==1)
            dp[n][m]=DP(n-1,0)+DP(n-1,2);
        else
            dp[n][m]=DP(n-1,0)+DP(n-1,1);
        dp[n][m]%=mod;
        return dp[n][m];
    }
    void start_dp(){
        std::cout << (DP(N,0)+DP(N,1)+DP(N,2))%mod <<'\n';
    }


};
int main(){
    zoo z;
    z.start_dp();
    return 0;
}