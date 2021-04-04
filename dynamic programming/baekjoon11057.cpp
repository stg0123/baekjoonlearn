#include <iostream>
#include <vector>
using namespace std;
int mod=10007;
class upper{
private:
    vector<vector<int>> dp;
    int N;
public:
    upper(){
        std::cin >> N;
        dp.resize(N+1,vector<int>(10,-1));
        for(int i=0;i<10;i++)
            dp[1][i]=1;
    }
    int DP(int n,int idx){
        if(dp[n][idx]!=-1)
            return dp[n][idx];
        dp[n][idx]=0;
        for(int i=idx;i<10;i++)
            dp[n][idx]+=DP(n-1,i);
        dp[n][idx]%=mod;
        return dp[n][idx];
    }
    void find_sol(){
        int sol=0;
        for(int i=0;i<10;i++)
            sol+=DP(N,i);
        sol%=mod;
        std::cout << sol;
    }
};
int main(){
    upper ur;
    ur.find_sol();

    return 0;
}