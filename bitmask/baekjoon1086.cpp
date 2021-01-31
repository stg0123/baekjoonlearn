#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
struct _node{
    int length;
    int remainder;
};
class park{
private:
    vector<int> leng_remainder;
    vector<string> num;
    vector<_node> val;
    vector<vector<ll>> dp;
    int MOD,N;
    ll factorial;
public:
    park(){
        factorial=1;
        std::cin >> N;
        val.resize(N);
        num.resize(N);
        leng_remainder.resize(55,0);
        set_val();
        dp.resize(1<<N,vector<ll>(MOD,-1));
    }
    void set_val(){
        for(int i=0;i<N;i++){
            std::cin >> num[i];
            factorial*=i+1;
        }
        std::cin >>MOD; 
        int tmp_remainder;
        for(int i=0;i<N;i++){
            tmp_remainder=0;
            for(int j=0;j<num[i].size();j++){
                tmp_remainder=((tmp_remainder*10)%MOD+(num[i][j]-48)%MOD)%MOD;
            }
            val[i].remainder=tmp_remainder;
            val[i].length=num[i].size();
        }
        leng_remainder[0]=1%MOD;
        for(int i=1;i<55;i++){
            leng_remainder[i]=(leng_remainder[i-1]*10)%MOD;
        }
    }
    void start_dp(){
        ll tmp = DP(0,0);
        if(tmp==0)
            std::cout << "0/1";
        else{
            ll g =gcd(factorial,tmp);
            std::cout <<tmp/g << '/'<<factorial/g;
        }
    }
    ll DP(int bitmask,int mod){
        if(dp[bitmask][mod]!=-1)
            return dp[bitmask][mod];

        if(bitmask==(1<<N)-1){
            if(mod)
                return 0;
            else 
                return 1;
        }
        dp[bitmask][mod]=0;
        for(int i=0;i<N;i++){
            if(!(bitmask&(1<<i))){
                int tmp =mod*leng_remainder[val[i].length]+val[i].remainder;
                dp[bitmask][mod]+=DP(bitmask|(1<<i),tmp%MOD);
            }
        }
        return dp[bitmask][mod];
    }
    ll gcd(ll a,ll b){
        a=a%b;
        if(a==0)
            return b;
        return gcd(b,a);
    }

};
int main(){
    park p;
    p.start_dp();
    return 0;
}