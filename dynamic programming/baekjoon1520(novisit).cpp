#include <iostream>
#include <vector>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
class stair_num{
private:
    vector<vector<int>> map,dp;
    vector<vector<bool>> visit;
    int N,M;
public:
    stair_num(int n,int m):N(n),M(m){
        map.resize(n+1);
        dp.resize(n+1);
        visit.resize(n+1);
        for(int i=0;i<=n;i++){
            map[i].resize(m+1);
            dp[i].resize(m+1,-1);
            visit[i].resize(m+1,false);
        }
    };

    void set_val(){
        int n;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++){
                std::cin >> map[i][j];
            }
        dp[N][M]=1;
        visit[1][1]=true;
    }


    int DP(int n,int m){
        if(dp[n][m]!=-1)
            return dp[n][m];
        int sol=0;
        for(int i=0;i<4;i++){
            if(n+dx[i]>0&&n+dx[i]<=N&&m+dy[i]>0&&m+dy[i]<=M&&map[n][m]>map[n+dx[i]][m+dy[i]]){
                sol+=DP(n+dx[i],m+dy[i]);
            }
        }
            dp[n][m]=sol;
        return dp[n][m];
    }


};
int main(){
    int n,m;
    std::cin >> n>>m;
    stair_num st(n,m);
    st.set_val();
    std::cout << st.DP(1,1)<<'\n';


    return 0;
}