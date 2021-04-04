#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int mod=1e9;
class sds{
private:
    vector<vector<ll>> dp;
    int N,K;
public:
    sds(){
        std::cin >> N >> K;
        dp.resize(N+1,vector<ll>(K+1,-1));
    }
    ll DP(int n,int k){
        if(k==1)
            return 1;
        if(dp[n][k]!=-1)
            return dp[n][k];
        dp[n][k]=0;
        for(int i=0;i<=n;i++){
            dp[n][k]+=DP(n-i,k-1);
        }
        dp[n][k]%=mod;
        return dp[n][k];
    }
    void find_sol(){
        std::cout << DP(N,K);
    }
};
int main(){
    sds ss;
    ss.find_sol();
    return 0;
}