#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
ll MAX = 1000000000000;
class test3{
private:
    vector<ll> dp;
    int N;
public:
    test3(int t):N(t){
        dp.resize(16,0);
        dp[0]=1;
    }
    ll DP(int n){
        if(dp[n]!=0)
            return dp[n];
        dp[n]=DP(n-1)*n;
        return dp[n];

    }
    ll find_sol(){
        set<ll> S;
        for(int i=1;i<15;i++){
            int left=1;
            int right=left+i;
            ll tmp = DP(right);
            while(1){
                if(tmp>MAX)
                    break;
                S.insert(tmp);
                tmp/=left;
                left++;
                right++;
                tmp*=right;
            }
        }
        int n=0;
        for(ll sol : S){
            n++;
            if(n==N)
                return sol;
        }
        return 0;
    }


};
int main(){
    test3 t3(10);
    std::cout << t3.find_sol()<<'\n';

    return 0;
}