#include <iostream>
#include <vector>
using namespace std;
int INF=1000000000;
class test2{
private:
    vector<vector<int>> dp;
    vector<vector<int>> cost;
    int xcost,ycost;
    int N,M;
public:
    test2(vector<vector<int>> costs,int x,int y):cost(costs),xcost(y),ycost(x){
        N=cost.size();
        M=cost[0].size();
        dp.resize(N,vector<int>(M,-INF)); 
        dp[0][0]=cost[0][0];
    }
    int DP(int x,int y){
        if(dp[x][y]!=-INF)
            return dp[x][y];
        dp[x][y]=cost[x][y];
        if(x==0)
            dp[x][y]+=DP(x,y-1)-ycost;
        else if(y==0)
            dp[x][y]+=DP(x-1,y)-xcost;
        else
            dp[x][y]+=max(DP(x,y-1)-ycost,DP(x-1,y)-xcost);
        return dp[x][y];
    }
    int find_sol(){
        int sol=0;
        for(int i=0;i<M;i++){
            sol=max(DP(N-1,i),sol);
        }
        return sol;


    }
};
int main(){
    test2 t2({{1,2,3},{4,5,6},{7,8,9}},100,0);
    std::cout << t2.find_sol() << '\n';


    return 0;
}