#include <iostream>
#include <vector>
using namespace std;
class sit{
private:
    vector<int> dp;
    vector<bool> check;
    int N;
public:
    sit(){
        std::cin >> N;
        dp.resize(N+1,0);
        check.resize(N+1,false);
        set_val();
    }
    void set_val(){
        int M,n;
        std::cin >>M;
        for(int i=0;i<M;i++){
            std::cin >> n;
            check[n]=true;
        }
        dp[0]=1;
        dp[1]=1;
    }
    void find_sol(){
        for(int i=2;i<=N;i++){
            if(check[i-1])
                dp[i]=dp[i-1];
            else if(check[i])
                dp[i]=dp[i-1];
            else
                dp[i]=dp[i-1]+dp[i-2];
                
            
        }
        std::cout << dp[N]<<'\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    sit s;
    s.find_sol();

    return 0;
}