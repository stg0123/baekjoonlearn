#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class gitar{
private:
    vector<unordered_set<int>> dp;
    int N,S,M;
public:
    gitar(){
        std::cin >> N >> S >> M;
        dp.resize(N+1);
        dp[0].insert(S);
    }
    void find_sol(){
        int a;
        int sol=0;
        for(int i=0;i<N;i++){
            std::cin >> a;
            for(int p : dp[i]){
                if(p+a<=M){
                    dp[i+1].insert(p+a);
                    if(i==N-1)
                        sol=max(sol,p+a);
                }
                if(p-a>=0){
                    dp[i+1].insert(p-a);
                    if(i==N-1)
                        sol=max(sol,p-a);
                }
            }
        }
        if(dp[N].empty())
            std::cout << -1 <<'\n';
        else
            std::cout << sol << '\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    gitar gt;
    gt.find_sol();

    return 0;
}