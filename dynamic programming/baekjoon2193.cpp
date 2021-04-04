#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class pinary{
private:
    vector<ll> dp;
    int N;
public:
    pinary(){
        std::cin >> N;
        dp.resize(N+1,-1);
        dp[0]=dp[1]=dp[2]=1;
    }
    ll DP(int n){
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=DP(n-1)+DP(n-2);
        return dp[n];
    }
    void start_dp(){
        std::cout << DP(N);
    }
};
int main(){
    pinary pi;
    pi.start_dp();
    return 0;
}