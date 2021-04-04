#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class tilecode{
private:
    vector<ll> dp;
    int N;
public:
    tilecode(){
        std::cin >> N;
        dp.resize(N+1,-1);
        dp[0]=1;
        dp[1]=1;
    }
    ll DP(int n){
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=DP(n-1)+DP(n-2)*2;
        return dp[n];
    }
    void find_sol(){
        ll sol;
        if(N%2==0)
            sol =DP(N)+DP(N/2)+DP(N/2-1)*2;
        else
            sol =DP(N)+DP(N/2);
        
        std::cout << sol/2;
    }

};
int main(){
    tilecode tc;
    tc.find_sol();
    return 0;
}