#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
struct node{
    int score=0;
    int appach=0;
    vector<int> shot;
};
class test4{
private:
    vector<vector<node>> dp;
    int N;
public:
    test4(int n):N(n){
    }
    vector<int> find_sol(vector<int>& info){
        int all_appach=0;
        for(int i=0;i<info.size();i++){
            if(info[i])
                all_appach+=10-i;
        }
        dp.resize(12,vector<node>(N+1,{0,all_appach}));
        for(int i=1;i<=11;i++){
            for(int j=1;j<=N;j++){
                if(j>info[i-1]){
                    int appach=0;
                    int score = dp[i-1][j-info[i-1]-1].score+11-i;
                    if(info[i-1])
                        appach=11-i;
                    if(score>=dp[i-1][j].score && score-(dp[i-1][j-info[i-1]-1].appach-appach)>=dp[i-1][j].score-dp[i-1][j].appach){
                        dp[i][j].score=dp[i-1][j-info[i-1]-1].score+11-i;
                        dp[i][j].shot=dp[i-1][j-info[i-1]-1].shot;
                        dp[i][j].shot.push_back(11-i);
                        dp[i][j].appach=dp[i-1][j-info[i-1]-1].appach-appach;
                        continue;
                    }
                }
                dp[i][j]=dp[i-1][j];
            }
        }
        if(dp[10][N].appach>=dp[10][N].score)
            return {-1};
        vector<int> sol(11,0);
        int sum=0;
        for(int i : dp[10][N].shot){
            sol[10-i]=info[10-i]+1;
            sum+=sol[10-i];
        }
        if(sum<N)
            sol[10]+=N-sum;
        return sol;
    }
};
vector<int> solution(int n, vector<int> info) {
    test4 t4(n);
    return t4.find_sol(info);;
}
int main(){
    solution(1,{1,0,0,0,0,0,0,0,0,0,0});

    return 0;
}