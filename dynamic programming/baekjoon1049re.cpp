#include <iostream>
#include <vector>
#define INF 100000000
using namespace std;
class RGB{
private:
    vector<vector<int>> dp;
    vector<vector<int>> val;
    int N;
public:
    RGB(){
        std::cin >> N;
        dp.resize(N,vector<int>(3,INF));
        val.resize(N,vector<int>(3));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<3;j++)
                std::cin >>val[i][j];
    }
    void start_dp(){
        int sol=INF;
        for(int i=0;i<3;i++){
            sol=min(sol,DP(0,i));
        }
    
        std::cout << sol;
    }
    int DP(int n,int rgb){
        if(dp[n][rgb]!=INF)
            return dp[n][rgb];
        if(n==N-1)
            return val[n][rgb];

        dp[n][rgb]=min(DP(n+1,(rgb+1)%3),DP(n+1,(rgb+2)%3))+val[n][rgb];
        return dp[n][rgb];
    }

};
int main(){
    RGB r;
    r.start_dp();

    return 0;
}