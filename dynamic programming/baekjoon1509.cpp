#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;
class pelindrom{
private:
    vector<vector<int>> dp;
    vector<int> min_cut;
    string str;
public:
    pelindrom(){
        std::cin >> str;
        dp.resize(str.size()+1,vector<int>(str.size()+1,-1));
        min_cut.resize(str.size()+1,INF);
    }
    int DP(int start,int end){
        if(start>=end)
            return 1;
        if(dp[start][end]!=-1)
            return dp[start][end];
        dp[start][end]=DP(start+1,end-1)&&str[start-1]==str[end-1];
        return dp[start][end];
    }
    int sol_DP(int n){
        if(n<=1)
            return n;
        if(min_cut[n]!=INF)
            return min_cut[n];
        for(int i=1;i<=n;i++){
            if(DP(i,n))
                min_cut[n]=min(min_cut[n],1+sol_DP(i-1));
        }
        return min_cut[n];
    }
    void find_sol(){
        std::cout << sol_DP(str.size())  <<'\n';
    }

};
int main(){
    pelindrom pe;
    pe.find_sol();

    return 0;
}