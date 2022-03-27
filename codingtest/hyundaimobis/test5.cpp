#include <iostream>
#include <vector>
using namespace std;
int mod= 1000000007;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
class test5{
private:
    vector<vector<vector<int>>> dp;
    int N;
public:
    test5(int T):N(T){
        dp.resize(N+1,vector<vector<int>>(3,vector<int>(10,-1)));
        dp[1][0][6]=dp[1][1][5]=dp[1][1][7]=dp[1][2][6]=1;
    }
    int DP(int n,int x,int y){
        if(n==0)
            return 0;
        if(dp[n][x][y]!=-1)
            return dp[n][x][y];
        dp[n][x][y]=0;
        int nx,ny;
        for(int i=0;i<4;i++){
            nx=x+dx[i],ny=y+dy[i];
            if(nx<0 || nx>2 || ny<0 || ny>9 || (nx==1 && ny>8) || (nx==2 && ny>6))
                continue;
            dp[n][x][y]+=DP(n-1,nx,ny);
            dp[n][x][y]&=mod;
        }
        return dp[n][x][y];

    }

    int find_sol(){
        return DP(N,1,6);
    }
};
int main(){
    test5 t5(2);
    std::cout << t5.find_sol() << "\n";
    return 0;
}