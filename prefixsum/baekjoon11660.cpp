#include <iostream>
#include <vector>
using namespace std;
class interval_sum{
private:
    vector<vector<int>> dp;
    vector<vector<int>> map;
    int N,M;
public:
    interval_sum(){
        std::cin >> N >> M;
        dp.resize(N+1,vector<int>(N+1,0));
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                std::cin >> tmp;
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+tmp;
            }
        }
    }
    void find_sol(){
        int x1,y1,x2,y2;
        for(int i=0;i<M;i++){
            std::cin >>x1 >>y1 >> x2 >>y2;
            std::cout << dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1]<<'\n';
        }
    }

};
int main(){
    interval_sum is;
    is.find_sol();
    return 0;
}