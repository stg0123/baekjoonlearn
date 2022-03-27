#include <iostream>
#include <vector>
using namespace std;
int mod =1000000009;
class pus{
private:
    vector<int> dp;
    int size=1000000;
public:
    pus(){
        dp.resize(size+1,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
    }
    int DP(int n){
        if(dp[n]!=0)
            return dp[n];
        dp[n]=((DP(n-1)+DP(n-2))%mod+DP(n-3))%mod;
        return dp[n];
    }
    void find_sol(){
        int a;
        std::cin >> a;
        std::cout << DP(a)<<'\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    pus p;
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++)
        p.find_sol();

    return 0;
}