#include <iostream>
#include <vector>
using namespace std;
class big_rectangle{
private:
    vector<vector<int>> dp;
    vector<vector<int>> map;
    int N,M;
public:
    big_rectangle(){
        std::cin >> N >> M ;
        dp.resize(N,vector<int>(M,-1));
        map.resize(N,vector<int>(M,0));
        set_val();
    }
    void set_val(){
        char ch;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                std::cin >> ch;
                if(ch=='1')
                    map[i][j]=1;
            }
        }
    }
    int DP(int n,int m){
        if(n<0 || m<0)
            return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(map[n][m]==0)
            dp[n][m]=0;
        else 
            dp[n][m]=min(DP(n-1,m-1),min(DP(n-1,m),DP(n,m-1)))+1;
        return dp[n][m];
    }
    void start_dp(){
        int sol=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                sol=max(sol,DP(i,j));
            }
        }
        std::cout << sol*sol<<'\n';
    }

};
int main(){
    big_rectangle br;
    br.start_dp();
    return 0;
}
