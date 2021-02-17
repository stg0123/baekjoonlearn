#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int powmod=10007;
class tailing{
private:
    vector<int> dp;
    int N;
public:
    tailing(){
        std::cin >> N;
        dp.resize(N+3,0);
        dp[1]=1;
        dp[2]=3;
    }
    int DP(int n){
        if(dp[n]!=0)
            return dp[n];
        dp[n]=(DP(n-2)*2 + DP(n-1))%powmod;
        return dp[n];
    }
    void find_dp(){
        std::cout << DP(N);

    }

};
int main(){
    tailing t;
    t.find_dp();
    return 0;
}