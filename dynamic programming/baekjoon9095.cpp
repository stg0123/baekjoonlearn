#include <iostream>
#include <vector>
using namespace std;
class sum123{
private:
    vector<int> dp;
public:
    sum123(){
        dp.resize(12,-1);
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
    }
    int DP(int n){
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=DP(n-1)+DP(n-2)+DP(n-3);
        return dp[n];
    }

};
int main(){
    sum123 sum;
    int n,tmp;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> tmp;
        std::cout << sum.DP(tmp)<< '\n';
    }

    return 0;
}