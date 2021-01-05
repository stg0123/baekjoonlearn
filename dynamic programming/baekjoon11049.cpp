#include <iostream>
#include <vector>

#define INF 2100000000
using namespace std;
class min_opernum{
private:
    vector<pair<int,int>> map;
    vector<vector<int>> dp;
    int N;
public:
    min_opernum(int n):N(n){
        map.resize(n+1);
        dp.resize(n+1);
        for(int i=0;i<=n;i++)
            dp[i].resize(n+1,INF);
    };
    void set_val(){
        int tmp1,tmp2;
        for(int i=1;i<=N;i++){
            std::cin >> tmp1>>tmp2;
            map[i]=make_pair(tmp1,tmp2);   
        }
    }

    int DP(int start,int end){
        if(start==end)
            return 0;
        else if(start+1 == end)
            return map[start].first*map[start].second*map[end].second;
        else if(dp[start][end]!=INF)
            return dp[start][end];

        for(int mid=start;mid<end;mid++){
            dp[start][end]=min(dp[start][end],DP(start,mid)+DP(mid+1,end)+map[start].first*map[mid].second*map[end].second);
        }
        print_dp();
        return dp[start][end];
        
    }

    void print_dp(){
        std::cout<<'\n';
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++)
                std::cout << dp[i][j]<<' ';
            std::cout<<'\n';
        }
            
    }

};
int main(){
    int n;
    std::cin>>n;

    min_opernum mo(n);
    mo.set_val();
    std::cout << mo.DP(1,n)<<'\n';

    return 0;
}