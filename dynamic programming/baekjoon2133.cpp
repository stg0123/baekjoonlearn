#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class three_tile{
private:
    vector<ll> dp;
    int N;
public:
    three_tile(){
        std::cin >> N;
        dp.resize(N+1,0);
        dp[0]=1;
        dp[2]=3;
    }
    ll DP(int n){
        if(n%2==1)
            return 0;
        if(dp[n]!=0)
            return dp[n];
        dp[n]=DP(n-2)*3;
        int i=2;
        while(1){
            if(n-2*i<0)
                break;
            dp[n]+=DP(n-2*i)*2;
            i++;
        }
        return dp[n];
    }
    void start_dp(){
        std::cout << DP(N);

    }

};
int main(){
    three_tile tt;
    tt.start_dp();
    return 0;
}