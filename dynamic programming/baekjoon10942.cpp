#include <iostream>
#include <vector>
using namespace std;
class pelindrom{
private:
    vector<int> map;
    vector<vector<int>> dp;
    int N;
public:
    pelindrom(int n):N(n){
        map.resize(n+1);
        dp.resize(n+1);
        for(int i=0;i<=n;i++)
            dp[i].resize(n+1,-1);
    };
    
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> map[i];
    }

    bool DP(int start,int end){
        if(start>=end)
            return true;
        else if(dp[start][end]!=-1)
            return dp[start][end];

        dp[start][end]=DP(start+1,end-1)&&map[start]==map[end];
        return dp[start][end];

    };

};
int main(){
    int n,a,b;
    std::cin >> n;
    pelindrom pe(n);
    pe.set_val();
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> a>>b;
        std::cout << pe.DP(a,b)<<'\n';
    }
    return 0;
}