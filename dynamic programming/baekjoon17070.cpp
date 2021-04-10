#include <iostream>
#include <vector>
using namespace std;
class pipe{
private:
    vector<vector<vector<int>>> dp;
    vector<vector<int>> map;
    int N;
public:
    pipe(){
        std::cin >> N ;
        map.resize(N,vector<int>(N));
        dp.resize(N,vector<vector<int>>(N,vector<int>(3,-1)));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                std::cin >> map[i][j];
    }
    int DP(int n,int m,int idx){
        if(n==0 && m==1 && idx==0)
            return 1;
        if(n<0 ||m<=1 || map[n][m])
            return 0;
        if(dp[n][m][idx]!=-1)
            return dp[n][m][idx];
        dp[n][m][idx]=0;
        if(idx==0)
            dp[n][m][idx]=DP(n,m-1,2)+DP(n,m-1,0);
        else if(idx==1)
            dp[n][m][idx]=DP(n-1,m,2)+DP(n-1,m,1);
        else if(idx==2){
            if(n>0&&m>0){
                if(map[n-1][m]==0 && map[n][m-1]==0)
                    dp[n][m][idx]=DP(n-1,m-1,0)+DP(n-1,m-1,1)+DP(n-1,m-1,2);
            }
        }
        return dp[n][m][idx];

    }
    void start_dp(){
        std::cout << DP(N-1,N-1,0)+DP(N-1,N-1,1)+DP(N-1,N-1,2);

    }
};
int main(){
    pipe pp;
    pp.start_dp();
    return 0;
}