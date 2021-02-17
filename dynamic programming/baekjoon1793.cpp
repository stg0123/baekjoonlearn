#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
class bigtile{
private:
    vector<string> dp;
public:
    bigtile(){
        dp.resize(252);
        dp[0].push_back('1');
        dp[1].push_back('1');
        dp[2].push_back('3');
    }

    string add(string a,string b){
        string result;
        int sum=0;
        while(!a.empty()||!b.empty()||sum){
            if(!a.empty()){
                sum+=a.back()-'0';
                a.pop_back();
            }
            if(!b.empty()){
                sum+=b.back()-'0';
                b.pop_back();
            }
            result.push_back((sum%10)+'0');
            sum/=10;
        }
        reverse(result.begin(),result.end());
        return result;
    }
    string DP(int n){
        if(!dp[n].empty())
            return dp[n];
        dp[n]=add(add(DP(n-2),DP(n-2)),DP(n-1));
        return dp[n];
    }
    void start_dp(int N){
        std::cout << DP(N)<<'\n';
    }


};
int main(){
    bigtile bt;
    int n;
    while(1){
        std::cin >> n;
        if(cin.eof()==true)
            break;
        bt.start_dp(n);
    }

    return 0;
}