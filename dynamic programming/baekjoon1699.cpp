#include <iostream>
#include <vector>
#include <cmath>
#define INF 100000
using namespace std;
class powsum{
private:
    vector<int> dp;
    int N;
public:
    powsum(){
        std::cin >> N;
        dp.resize(N+1,INF);
    }
    int DP(int n){
        if(n<=1)
            return n;
        if(dp[n]!=INF)
            return dp[n];
        for(int i=1;i<=sqrt(n);i++){
            dp[n]=min(dp[n],DP(n-i*i)+1);
        }
        return dp[n];
    }
    void find_sol(){
        std::cout << DP(N);
    }

};
int main(){
    powsum ps;
    ps.find_sol();
    return 0;
}