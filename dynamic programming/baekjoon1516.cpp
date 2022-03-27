#include <iostream>
#include <vector>
using namespace std;
struct _node{
    int time;
    vector<int> first;
};
class craft{
private:    
    vector<int> dp;
    vector<_node> data;
    int N;
public:
    craft(){
        std::cin >> N;
        dp.resize(N+1,-1);
        data.resize(N+1);
        set_val();
    }
    void set_val(){
        int a;
        for(int i=1;i<=N;i++){
            std::cin >> data[i].time;
            while(1){
                std::cin >> a;
                if(a==-1)
                    break;
                data[i].first.push_back(a);
            }
        }
    }
    int DP(int n){
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=0;
        for(int i : data[n].first)
            dp[n]=max(DP(i),dp[n]);
        dp[n]+=data[n].time;
        return dp[n];
    }
    void find_sol(){
        for(int i=1;i<=N;i++)
            std::cout << DP(i)<<'\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    craft cft;
    cft.find_sol();

    return 0;
}