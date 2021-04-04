#include <iostream>
#include <vector>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
class panda{
private:
    vector<vector<int>> map;
    vector<vector<int>> dp;
    int N;
public:
    panda(){
        std::cin >> N;
        map.resize(N,vector<int>(N));
        dp.resize(N,vector<int>(N,-1));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                std::cin >> map[i][j];
    }
    int DP(int n,int m){
        if(dp[n][m]!=-1)
            return dp[n][m];
        int nx,ny;
        for(int i=0;i<4;i++){
            nx=n+dx[i],ny=m+dy[i];
            if(nx>=0&&nx<N && ny>=0 && ny<N){
                if(map[nx][ny]<map[n][m])
                    dp[n][m]=max(dp[n][m],DP(nx,ny));
            }
        }
        if(dp[n][m]==-1)
            dp[n][m]=1;
        else
            dp[n][m]+=1;
        return dp[n][m];
    }
    void start_dp(){
        int sol=0;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                sol=max(sol,DP(i,j));
        std::cout << sol << '\n';

    }

};
int main(){
    panda pd;
    pd.start_dp();
    return 0;
}