#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class koong{
private:
    vector<ll> dp;
    int N;
public:
    koong(){
        std::cin >> N;
        dp.resize(68);
        dp[0]=1,dp[1]=1,dp[2]=2,dp[3]=4;
    }
    ll DP(int n){
        if(dp[n])
            return dp[n];
        dp[n]=DP(n-1)+DP(n-2)+DP(n-3)+DP(n-4);
        return dp[n];
    }
    void find_sol(){
        int n;
        for(int i=0;i<N;i++){
            std::cin >> n;
            std::cout << DP(n)<<'\n';
        }
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    koong kg;
    kg.find_sol();
    return 0;
}