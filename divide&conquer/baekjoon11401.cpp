#include <iostream>
#include <vector>
using namespace std;
class pascal{
private:
    vector<int> dp;
    int N,M,mod;
public :
    pascal(int n,int m):N(n),M(m){
        dp.resize(n+1,0);
        dp[0]=dp[1]=1;
        mod=1000000007; 
    };
    long long pow(int a,int b){
        if(b==1)
            return a%mod;
        if(b%2==1)
            return (pow(a,b-1)*a)%mod;
        long long tmp=pow(a,b/2);
        return (tmp*tmp)%mod;
    }

    long long fac(int n){
        if(dp[n]!=0)
            return dp[n]%mod;
        dp[n]=(fac(n-1)*n)%mod;
        return dp[n];

    }
    void DQ(){
        long long A,B;
        A=fac(N);
        B=(fac(M)*fac(N-M))%mod;
        long long tmp=(A*pow(B,mod-2))%mod;
        std::cout <<tmp<<'\n';        

    }
};
int main(){
    int a,b;
    std::cin >> a>>b;
    pascal p(a,b);
    p.DQ();

    return 0;
}