#include <iostream>
#include <vector>
using namespace std;
class stair_num{
private:
    vector<vector<long>> chache;
    int N;
public:
    stair_num(int n):N(n){
        chache.resize(n+1);
        for(int i=1;i<=n;i++)
            chache[i].resize(10,-1);
        for(int i=1;i<10;i++)
            chache[1][i]=1;
        chache[1][0]=0;
    }
    
    long DP(int n,int m){
        if(n<=0||m<0)
            return 0;
        else if(chache[n][m]!=-1)
            return chache[n][m];
        
        if(m==0)
            chache[n][m]=DP(n-1,m+1);     
        else if(m==9)
            chache[n][m]=DP(n-1,m-1);
        else
            chache[n][m]=(DP(n-1,m-1)+DP(n-1,m+1))%1000000000;
        
        return chache[n][m];
    }

};

int main(){
    int n;
    std::cin >> n;
    stair_num s(n);
    long long sum=0;
    for(int i=0;i<10;i++)
        sum+=s.DP(n,i);
    std::cout << sum%1000000000<<'\n';
    return 0;
}