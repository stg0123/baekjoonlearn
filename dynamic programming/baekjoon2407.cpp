#include <iostream>
#include <vector>
using namespace std;
struct bignum{
    string str;
    bignum operator +(bignum b){
        int tmp=0,sum;
        int num1,num2;
        string sol;
        while(1){
            if(str.empty() && b.str.empty())
                break;
            if(str.empty())
                num1=0;
            else{
                num1=str.back()-'0';
                str.pop_back();
            }
            if(b.str.empty())
                num2=0;
            else{
                num2=b.str.back()-'0';
                b.str.pop_back();
            }
            sum=num1+num2+tmp;
            sol.push_back(sum%10+'0');
            tmp=sum/10;
        }
        if(tmp>0)
            sol.push_back(tmp+'0');
        bignum result;
        while(!sol.empty()){
            result.str.push_back(sol.back());
            sol.pop_back();
        }
        return result;
    }
};
typedef long long ll;
class pascal{
private:
    vector<vector<bignum>> dp;
    int N,M;
public:
    pascal(){
        std::cin >> N >> M;
        dp.resize(N+1,vector<bignum>(N+1,{"null"}));
    }
    bignum DP(int n,int m){
        if(m==0 || n==m)
            return {"1"};
        if(dp[n][m].str!="null")
            return dp[n][m];
        dp[n][m]=DP(n-1,m)+DP(n-1,m-1);
        return dp[n][m];
    }
    void start_dp(){
        std::cout << DP(N,M).str;
    }

};
int main(){
    pascal psc;
    psc.start_dp();
    return 0;
}