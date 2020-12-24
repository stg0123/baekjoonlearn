#include <iostream>
#include <vector>
#include <string>
using namespace std;
class LCS{
private:
    string s1,s2;
    vector<vector<int>> dp;
public :
    LCS(){

    };
    void set_val(){
        std::cin >> s1 >> s2;
        dp.resize(s1.size()+1);
        for(int i=0;i<s1.size()+1;i++)
            dp[i].resize(s2.size()+1,0);
    };
    
    void DP(){
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            print_dp();
        }
        std::cout << dp[s1.size()][s2.size()]<<'\n';
    };
    void print_dp(){
        std::cout <<'\n';
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[i].size();j++)
                std::cout << dp[i][j] << ' ';
            std::cout <<'\n';
        }
    }
    void print_sol(){
        string sol;
        int i=s1.size(),j=s2.size();
        while(1){
            if(dp[i][j]==0)
                break;
            if(dp[i][j]==dp[i][j-1])
                j--;
            else if(dp[i][j]==dp[i-1][j])
                i--;
            else if(dp[i][j]-1==dp[i-1][j-1]){
                sol.insert(sol.begin(),s2[j-1]);
                i--;
                j--;
            }
        }
        std::cout << sol<<'\n';
    }

};

int main(){
    LCS L;
    L.set_val();
    L.DP();
    L.print_sol();

    return 0;
}