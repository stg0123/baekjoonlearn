#include <iostream>
#include <vector>
using namespace std;
int dx[3]={-1,0,-1};
int dy[3]={0,-1,-1};
class move_{
private:
    vector<vector<int>> map;
    vector<vector<int>> dp;
    int N,M;
public:
    move_(){
        std::cin >> N >> M;
        dp.resize(N,vector<int>(M,-1));
        map.resize(N,vector<int>(M));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                std::cin >> map[i][j];
    }
    int DP(int n,int m){
        if(n==0&&m==0)
            return map[n][m];
        if(dp[n][m]!=-1)
            return dp[n][m];
        int nx,ny;
        for(int i=0;i<3;i++){
            nx=n+dx[i],ny=m+dy[i];
            if(nx>=0&&ny>=0)
                dp[n][m]=max(dp[n][m],DP(nx,ny));
        }
        dp[n][m]+=map[n][m];
        return dp[n][m];
    }  
    void start_dp(){
        std::cout << DP(N-1,M-1);
    }

};
int main(){
    move_ m;
    m.start_dp();
    
    return 0;
}