#include <iostream>
#include <vector>
#include <map>
#define INF 100000000
using namespace std;
class TSP{
private:
    vector<map<int,int>> dp;
    vector<vector<int>> val;
    int N,start;
public:
    TSP(){
        std::cin >> N;
        dp.resize(N+1);
        val.resize(N+1,vector<int>(N+1));
        set_val();
        start=1;
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                std::cin >> val[i][j];
    }
    void start_dp(){
        int bitmask=1;
        bitmask|=(1<<start);
        std::cout << DP(start,bitmask);
    }

    int DP(int n,int bitmask){
        if(dp[n][bitmask]){
            return dp[n][bitmask];
        }
        
        if(bitmask==(1<<N+1)-1){
            if(val[n][start]){
                return val[n][start];
            }
            else
                return INF;
        }
        dp[n][bitmask]=INF;
        int tmp;
        for(int i=1;i<=N;i++){
            if(!(bitmask&(1<<i))&&val[n][i]){
                bitmask|=(1<<i);
                tmp = DP(i,bitmask)+val[n][i];
                bitmask&=~(1<<i);
                dp[n][bitmask]=min(dp[n][bitmask],tmp);
            }
        }
        return dp[n][bitmask];
    }

};
int main(){
    TSP tsp;
    tsp.start_dp();

    return 0;
}