#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int powmod=1e9;
class mi_fibo{
private:
    vector<ll> dp;
    int N;
public:
    mi_fibo(){
        std::cin >> N;
        if(N>0)
            dp.resize(N+1,-1);
        else
            dp.resize(-N+1,-1);
        dp[0]=0;
        dp[1]=1;
        
    }
    ll DP(int n){
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=(DP(n-2)+DP(n-1))%powmod;
        return dp[n];
    }
    void find_sol(){
        if(N==0)
            std::cout << 0 << '\n' << 0;
        else if(N>0)
            std::cout << 1 << '\n' <<DP(N);
        else{
            N=-N;
            if(N%2==0)
                std::cout << -1 <<'\n'<<DP(N);
            else
                std::cout << 1 << '\n'<<DP(N);
        }
    }
};
int main(){
    mi_fibo mf;
    mf.find_sol();
    return 0;
}