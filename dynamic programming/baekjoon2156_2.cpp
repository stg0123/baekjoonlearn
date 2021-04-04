#include <iostream>
#include <vector>
using namespace std;
class podo{
private:
    vector<int> dp;
    vector<int> val;
    int N;
public:
    podo(){
        std::cin >> N;
        dp.resize(N+1,-1);
        val.resize(N+1,0);
        set_val();
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> val[i];
    }
    void start_dp(){
        dp[0]=0;
        dp[1]=val[1];
        dp[2]=val[1]+val[2];
        std::cout << DP(N);
    }
    int DP(int n){
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=max(DP(n-1),DP(n-2)+val[n]);
        dp[n]=max(dp[n],DP(n-3)+val[n-1]+val[n]);
        return dp[n];
    }
    


};
int main(){
    podo pd;
    pd.start_dp();
    return 0;
}