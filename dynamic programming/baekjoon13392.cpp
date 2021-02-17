#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;
class locknum{
private:
    vector<int> now;
    vector<int> password;
    vector<vector<int>> dp;
    int N;
public:
    locknum(){
        std::cin >>N;
        dp.resize(N,vector<int>(10,INF));
        set_val();
    }
    void set_val(){
        string str1,str2;
        std::cin >> str1>>str2;
        for(int i=0;i<N;i++){
            now.push_back(str1[i]-48);
            password.push_back(str2[i]-48);
        }
    }
    int DP(int n,int plus){
        int cur_num = (now[n]+plus)%10;
        int tmp;
        if(dp[n][plus]!=INF)
            return dp[n][plus];
        if(n==N-1){
            return dp[n][plus]=abs(cur_num-password[n]);
        }
        for(int i=0;i<10;i++){
            tmp=(cur_num+i)%10;
            if(tmp>=password[n])
                tmp-=password[n];
            else
                tmp= (10-password[n])+tmp;
            dp[n][plus]=min(dp[n][plus],DP(n+1,(plus+i)%10)+i+tmp);
        }
        return dp[n][plus];
    }
};
int main(){
    locknum lk;
    std::cout <<lk.DP(0,0);
    return 0;
}