#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int mod = 1000000009;
class _123plus{
private:
    vector<vector<ll>> dp;
public:
    _123plus(){
        dp.resize(100001,vector<ll>(3,-1));
        dp[1]={1,0,0};
        dp[2]={0,1,0};
        dp[3]={1,1,1};
    }
    ll DP(int n,int m){
        if(n<1)
            return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        dp[n][m]= DP(n-m-1,(m+1)%3)+DP(n-m-1,(m+2)%3);
        dp[n][m]%=mod;
        return dp[n][m];
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    _123plus p;
    int t,n;
    std::cin >> t;
    for(int i=0;i<t;i++){
        std::cin >> n;
        std::cout << (p.DP(n,0)+p.DP(n,1)+p.DP(n,2))%mod <<'\n';
    }

    return 0;
}