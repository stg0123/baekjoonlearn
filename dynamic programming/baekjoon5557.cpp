#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class first{
private:
    vector<int> arr;
    vector<vector<ll>> dp;
    int N;
public:
    first(){
        std::cin >>N;
        dp.resize(N,vector<ll>(21));
        set_val();
    }
    void set_val(){
        int a;
        for(int i=0;i<N;i++){
            std::cin >>a ;
            arr.push_back(a);
        }
        dp[0][arr[0]]=1;
    }
    ll DP(int a,int b){
        if(a<0 || b>20 || b<0)
            return 0;
        if(dp[a][b])
            return dp[a][b];
        dp[a][b]=DP(a-1,b+arr[a])+DP(a-1,b-arr[a]);
        return dp[a][b];
    }
    void find_sol(){
        std::cout << DP(N-2,arr[N-1]) <<'\n';
    }
};
int main(){
    first ft;
    ft.find_sol();
    return 0;
}