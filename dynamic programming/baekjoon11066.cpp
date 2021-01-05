#include <iostream>
#include <vector>
using namespace std;
#define INF 2100000000
class file_add{
private:
    vector<vector<int>> dp;
    int N;
public:
    file_add(int n):N(n){
        dp.resize(n+1);
        for(int i=0;i<=n;i++)
            dp[i].resize(n+1,INF);
    };
    void set_val(){
        for(int i=1;i<=N;i++){
           std::cin >> dp[i][i];
        }
    }

    int DP(int start,int end){
        if(start == end)
            return 0;
        else if(start+1==end)
            return dp[start][end] =dp[start][start]+dp[end][end];
        else if(dp[start][end]!=INF)
            return dp[start][end];

        for(int mid=start;mid<end;mid++){
            dp[start][end]=min(dp[start][end],DP(start,mid)+DP(mid+1,end));
        }
        for(int i=start;i<=end;i++)
            dp[start][end]+=dp[i][i];
        return dp[start][end];

    }
    void print_dp(){
        std::cout <<'\n';
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++)
                std::cout << dp[i][j]<<' ';
            std::cout <<'\n';
        }
    }

};

int main(){
    int n,tmp;
    std::cin >>n;
    for(int i=0;i<n;i++){
        std::cin >> tmp;
        file_add f(tmp);
        f.set_val();
        std::cout << f.DP(1,tmp)<<'\n';
    }


    return 0;
}