#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class fibo{
private:
    vector<string> dp;
    int N;
public:
    fibo(){
        std::cin >> N;
        dp.resize(3);
        dp[0]="0";
        dp[1]="1";
    }
    string sum(string x, string y)
    {
        int num;
        int carry = 0;
        string result;
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
    
        while (x.length() < y.length()) {
            x += '0';
        }
        while (x.length() > y.length()) {
            y += '0';
        }
    
        for (int i = 0; i < x.length(); ++i) {
            num = (x[i] - '0' + y[i] - '0' + carry) % 10;
            result += to_string(num);
            carry = (x[i] - '0' + y[i] - '0' + carry) / 10;
        }
        if (carry != 0) {
            result += to_string(carry);
        }
    
        reverse(result.begin(), result.end());
    
        return result;
    }
    void DP(){
        if(N<2)
            std::cout << dp[N]<<'\n';
        for(int i=2;i<=N;i++){
            dp[2]=sum(dp[0],dp[1]);
            dp[0]=dp[1];
            dp[1]=dp[2];
        }
        std::cout << dp[2] << '\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    fibo fi;
    fi.DP();

    return 0;
}