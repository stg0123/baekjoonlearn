#include <iostream>
#include <vector>
using namespace std;
class LCS{
private:
    string str1,str2;
    vector<vector<int>> dp;
public:
    LCS(){
        std::cin >> str1 >> str2;
        dp.resize(str1.size(),vector<int>(str2.size(),-1));
    }
    int DP(int a,int b){
        if(a<0 || b<0)
            return 0;
        if(dp[a][b]!=-1)
            return dp[a][b];
        if(str1[a]==str2[b])
            dp[a][b]=DP(a-1,b-1)+1;
        else 
            dp[a][b]=max(DP(a-1,b),DP(a,b-1));
        return dp[a][b];
    }    
    void find_sol(){
        std::cout << DP(str1.size()-1,str2.size()-1)<<'\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    LCS lcs;
    lcs.find_sol();

    return 0;
}