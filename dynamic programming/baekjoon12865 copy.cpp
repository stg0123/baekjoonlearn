#include <iostream>
#include <vector>
using namespace std;
class napsack{
private:
    vector<vector<int>> dp;
    int N,K;
public:
    napsack(){
        std::cin >> N >> K;
        dp.resize(N+1,vector<int>(K+1));
    }
    void find_sol(){
        int a,b;
        for(int i=1;i<=N;i++){
            std::cin >>a >> b;
            for(int j=1;j<=K;j++){
                if(j>=a)
                    dp[i][j]=max(dp[i-1][j-a]+b,dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        std::cout << dp[N][K]<<'\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    napsack nk;
    nk.find_sol();

    return 0;
}