#include <iostream>
#include <vector>
using namespace std;
class LIS{
private:
    vector<int> map;
    vector<int> dp;
    int N,max;
public:
    LIS(int n):N(n){
        map.resize(n);
        dp.resize(n,1);
        max=1;
    };
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> map[i];
    };

    void DP(){
        for(int i=0;i<N;i++)
            for(int j=0;j<i;j++){
                if(map[i]>map[j]&&dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    if(max<dp[i])
                        max=dp[i];
                }
            }
        std::cout << max <<'\n';
    };

    void print_sol(){
        vector<int> sol;
        for(int i=N-1;i>=0;i--){
            if(max==0)
                break;
            else if(dp[i]==max){
                sol.push_back(map[i]);
                max--;
            }
        }
        for(int i=sol.size()-1;i>=0;i--)
            std::cout << sol[i] << ' ';
        std::cout <<'\n';

    };
};
int main(){
    int n;
    std::cin >> n;
    LIS lis(n);
    lis.set_val();
    lis.DP();
    lis.print_sol();



    return 0;
}