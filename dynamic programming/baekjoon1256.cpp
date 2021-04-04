#include <iostream>
#include <vector>
using namespace std;
class dic{
private:
    vector<vector<int>> dp;
    int N,M,K;
    string word;
public:
    dic(){
        std::cin >> N >> M >> K;
        dp.resize(N+1,vector<int>(M+1,-1));

    }
    int DP(int n,int m){
        if(n==0 || m==0)
            return 1;
        if(dp[n][m]!=-1)
            return dp[n][m];
        dp[n][m]=min(DP(n-1,m)+DP(n,m-1),1000000000+1);
        return dp[n][m];
    }
    void find_sol(){
        if(DP(N,M)<K){
            std::cout << -1<<'\n';
            return ;
        }
        get_word(N,M,K-1);
        std::cout << word<<'\n';
    }
    void get_word(int A,int Z,int skip){
        if(A==0){
            for(int i=0;i<Z;i++)
                word+='z';
            return ;
        }   
        if(Z==0){
            for(int i=0;i<A;i++)
                word+='a';
            return ;
        }
        int idx=DP(A-1,Z);
        if(skip<idx){
            word+='a';
            get_word(A-1,Z,skip);
        }
        else{
            word+='z';
            get_word(A,Z-1,skip-idx);
        }
    }

};
int main(){
    dic dc;
    dc.find_sol();
    return 0;
}