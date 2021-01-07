#include <iostream>
#include <vector>
using namespace std;
class balance{
private:
    vector<int> map;
    vector<vector<int>> dp;
    int N,SUM;
public:
    balance(int n):N(n){
        map.resize(n+1,0);
        dp.resize(n+1);
    };
    void set_val(){
        int sum=0;
        for(int i=1;i<=N;i++){
            std::cin >>map[i];
            sum+=map[i];
        }
        SUM=sum;
        for(int i=0;i<=N;i++)
            dp[i].resize(SUM+1);
    }

    void knapsack(){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=SUM;j++){
                if(dp[i-1][j]){
                    dp[i][j]=true;
                    dp[i][j+map[i]]=true;
                    dp[i][abs(j-map[i])]=true;
                }
            }
            dp[i][map[i]]=true;
        }
    }

    void print_dp(){
        std::cout <<'\n';
        for(int i=1;i<=N;i++){
            for(int j=1;j<=SUM;j++)
                std::cout <<dp[i][j] << ' ';
            std::cout << '\n';
        }
    }

    void find(int n){
        if(n>SUM||n<=0){
            std::cout <<'N';
            return ;
        }
        if(dp[N][n]==true)
            std::cout<<'Y';
        else
            std::cout<<'N';
    }

};
int main(){
    int n,tmp;
    std::cin >>n;
    balance b(n);
    b.set_val();
    b.knapsack();
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> tmp;
        b.find(tmp);
        if(i!=n-1)
            std::cout << ' ';
    }
  

    return 0;
}
