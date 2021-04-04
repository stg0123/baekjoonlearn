#include <iostream>
#include <vector>
using namespace std;
class card{
private:
    vector<int> dp;
    int N;
    vector<int> val;
public:
    card(){
        std::cin >> N;
        val.resize(N+1);
        dp.resize(N+1,-1);
        dp[0]=0;
        set_val();
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> val[i];
    }
    int DP(int n){
        if(dp[n]!=-1)
            return dp[n];
        for(int i=1;i<=n;i++)
            dp[n]=max(dp[n],DP(n-i)+val[i]);
        return dp[n];
    }
    void start_dp(){
        std::cout << DP(N);
    }

};
int main(){
    card cd;
    cd.start_dp();
    return 0;
}