#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class LCS{
private:
    vector<vector<int>> dp;
    string str1,str2;
public:
    LCS(){
        std::cin >> str1 >> str2;
        dp.resize(str2.size()+1);
    }

    void DP(){
        dp[0].resize(str1.size()+1,0);
        for(int i=1;i<=str2.size();i++){
            dp[i].resize(str1.size()+1,0);
            for(int j=1;j<=str1.size();j++){
                if(str2[i-1]==str1[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        std::cout << dp[str2.size()][str1.size()]<<'\n';
    }

    void find_LCS(){
        int tmp = dp[str2.size()][str1.size()];
        int x=str2.size(),y=str1.size();
        stack<char> st;
        while(1){
            if(tmp==dp[x-1][y])
                x--;
            else if(tmp==dp[x][y-1])
                y--;
            else{
                tmp--;
                x--;
                y--;
                st.push(str1[y]);
            }
            if(tmp==0)
                break;
        }
        while(!st.empty()){
            std::cout << st.top();
            st.pop();
        }
        std::cout <<'\n';

    }
    
};
int main(){
    LCS L;
    L.DP();
    L.find_LCS();
    return 0;

}