#include <iostream>
#include <vector>
using namespace std;
class tiling{
private:
    vector<vector<int>> dp;
    int N,M;
public:
    tiling(){
        std::cin >> N;
        M=4;
        dp.resize(N*M,vector<int>(1<<M,-1));
    }
    int DP(int n,int bit){
        if(n==M*N)
            return bit==0;
        if(n>M*N)
            return 0;
        if(dp[n][bit]!=-1)
            return dp[n][bit];
            
        if(bit&1){
            dp[n][bit]=DP(n+1,bit>>1);
        }
        else{
            dp[n][bit]=DP(n+1,bit>>1|1<<(M-1));
            if(n%M!=M-1 && !(bit&2)){
                dp[n][bit]+=DP(n+2,bit>>2);
            }
        }
        return dp[n][bit];
    }


};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        tiling ti;
        std::cout << ti.DP(0,0)<<'\n';
    }
    return 0;
}