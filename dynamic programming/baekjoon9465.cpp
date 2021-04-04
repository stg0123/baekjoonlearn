#include <iostream>
#include <vector>
using namespace std;
class sticker{
private:
    vector<vector<int>> dp;
    int N;
    vector<vector<int>> map;
public:
    sticker(){
        std::cin >> N;
        dp.resize(2,vector<int>(N+1,-1));
        map.resize(2,vector<int>(N+1));
        set_val();
    }
    void set_val(){
        for(int i=0;i<2;i++)
            for(int j=1;j<=N;j++)
                std::cin >> map[i][j];
        for(int i=0;i<2;i++)
            dp[i][1]=map[i][1];
        for(int i=0;i<2;i++)
            dp[i][2]=dp[(i+1)%2][1]+map[i][2];
    }

    int DP(int idx,int n){
        if(dp[idx][n]!=-1)
            return dp[idx][n];
        dp[idx][n]=max(max(DP(idx,n-2),DP((idx+1)%2,n-1)),DP((idx+1)%2,n-2))+map[idx][n];
        return dp[idx][n];
    }
    void start(){
        int sol=0;
        for(int i=N-1;i<=N;i++){
            for(int j=0;j<2;j++){
                sol=max(sol,DP(j,i));
            }
        }
        std::cout << sol<<'\n';
    }
};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        sticker stk;
        stk.start();
    }
    return 0;
}