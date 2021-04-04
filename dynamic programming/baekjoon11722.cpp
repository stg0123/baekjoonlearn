#include <iostream>
#include <vector>
using namespace std;
class LDS{
private:
    vector<int> dp;
    int N;
    vector<int> val;
public:
    LDS(){
        std::cin >> N;
        dp.resize(N+1,-1);
        val.resize(N+1);
        set_val();
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> val[i];
    }
    int DP(int n){
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=1;
        for(int i=1;i<n;i++){
            if(val[n]<val[i])
                dp[n]=max(dp[n],DP(i)+1);
        }
        return dp[n];
    }
    void start_dp(){
        int sol=0;
        for(int i=1;i<=N;i++)
            sol=max(sol,DP(i));
        std::cout << sol;
    }
};
int main(){
    LDS lds;
    lds.start_dp();
    return 0;
}