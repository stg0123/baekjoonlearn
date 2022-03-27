#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int INF =1000000000;
class jump_jump{
private:
    vector<int> dp;
    vector<int> num;
    int N;
public:
    jump_jump(){
        std::cin >> N;
        dp.resize(N,INF);
        dp[0]=0;
        num.resize(N);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> num[i];
        for(int i=0;i<N-1;i++){
            for(int j=1;j<=num[i];j++)
                if(i+j<N)
                    dp[i+j]=min(dp[i+j],dp[i]+1);
        }
    }
    void find_sol(){
        if(dp[N-1]==INF)
            std::cout << -1 << '\n';
        else
            std::cout << dp[N-1] << '\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    jump_jump jj;
    jj.find_sol();
    return 0;
}