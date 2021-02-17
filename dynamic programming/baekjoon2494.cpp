#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;
struct _node{
    int sum;
    int plus;
    int minus;
    
};
class locknum{
private:
    vector<int> now;
    vector<int> password;
    vector<vector<_node>> dp;
    int N;
public:
    locknum(){
        std::cin >> N;
        dp.resize(N,vector<_node>(10,{INF,0,0}));
        set_val();
    }
    void set_val(){
        string str1,str2;
        std::cin >> str1 >> str2;
        for(int i=0;i<N;i++){
            now.push_back(str1[i]-48);
            password.push_back(str2[i]-48);
        }
    }
    _node DP(int n,int plus){
        int cur_num=(now[n]+plus)%10;
        int tmp,tmp2;
        if(dp[n][plus].sum!=INF)
            return dp[n][plus];
        if(n==N-1){
            if(password[n]>cur_num){
                tmp = password[n]-cur_num;
                tmp2= (10-password[n])+cur_num;
                if(tmp>tmp2)
                    dp[n][plus]={tmp2,0,tmp2};
                else
                    dp[n][plus]={tmp,tmp,0}; 
            }
            else{
                tmp =cur_num-password[n];
                tmp2=(10-cur_num)+password[n];
                if(tmp>tmp2)
                    dp[n][plus]={tmp2,tmp2,0};
                else
                    dp[n][plus]={tmp,0,tmp};
            }
            return dp[n][plus];
        }
        for(int i=0;i<10;i++){
            tmp = (cur_num+i)%10;
            if(tmp>=password[n])
                tmp -= password[n];
            else
                tmp = (10-password[n])+tmp;
            tmp2=DP(n+1,(plus+i)%10).sum+i+tmp;
            if(dp[n][plus].sum>tmp2){
                dp[n][plus].sum=tmp2;
                dp[n][plus].plus=i;
                dp[n][plus].minus=tmp;
            }
        }
        return dp[n][plus];
    }
    void start_dp(){
        std::cout << DP(0,0).sum<<'\n';
        int p=0;
        for(int i=0;i<N;i++){
            std::cout<<i+1 << ' ' << dp[i][p].plus-dp[i][p].minus<<'\n';
            p=(p+dp[i][p].plus)%10;
        }
    }
    

};
int main(){
    locknum lk;
    lk.start_dp();

    return 0;
}