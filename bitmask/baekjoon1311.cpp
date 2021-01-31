#include <iostream>
#include <vector>
#include <map>
#define INF 100000000
using namespace std;
class work_min{
private:
    vector<vector<int>> dp;
    vector<vector<int>> val;
    int N;
public:
    work_min(){
        std::cin >>N;
        val.resize(N,vector<int>(N));
        dp.resize(N,vector<int>(1<<N,INF));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                std::cin >> val[i][j];
    }

    void start_dp(){
        std::cout << DP(0,0);
    }
    int DP(int n,int bitmask){
        if(bitmask==(1<<N)-1)
            return 0;
            
        if(dp[n][bitmask]!=INF)
            return dp[n][bitmask];
            
        for(int i=0;i<N;i++){
            if(!(bitmask&(1<<i))){
                dp[n][bitmask]=min(dp[n][bitmask],DP(n+1,bitmask|(1<<i))+val[n][i]);
            }
        }
        return dp[n][bitmask];
    }

    
};
int main(){
    work_min wm;
    wm.start_dp();
    return 0;
}