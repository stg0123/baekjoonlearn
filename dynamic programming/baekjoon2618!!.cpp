#include <iostream>
#include <vector>
using namespace std;
class police{
private:
    vector<vector<int>> dp;
    vector<pair<int,int>> event;
    vector<vector<int>> car;
    int N,M;
public:
    police(){
        std::cin >> N >> M;
        dp.resize(M+2,vector<int>(M+2,-1));
        car.resize(M+2,vector<int>(M+2));
        event.resize(M+2);
        set_val();
    }
    void set_val(){
        int x,y;
        for(int i=2;i<M+2;i++){
            std::cin >>event[i].first>> event[i].second;
        }
        event[0].first=event[0].second=1;
        event[1].first=event[1].second=N;
    }
    int dis(pair<int,int>& a ,pair<int,int>& b){
        return abs(a.first-b.first) +abs(a.second-b.second);
    }
    int DP(int a,int b){
        if(dp[a][b]!=-1)
            return dp[a][b];
        int now = max(a,b)+1;
        if(now == M+2)
            return 0;
        dp[a][b]=DP(now,b)+dis(event[a],event[now]);
        int tmp = DP(a,now)+dis(event[b],event[now]);

        if(dp[a][b]>tmp){
            dp[a][b]=tmp;
            car[a][b]=2;
        }
        else
            car[a][b]=1;

        return dp[a][b];
    }
    void start_dp(){
        std::cout <<DP(0,1) << '\n';
        int a=0,b=1;
        for(int i=0;i<M;i++){
            std::cout << car[a][b] << '\n';
            if(car[a][b]==1)
                a=max(a,b)+1;
            else
                b=max(a,b)+1;
        }
    }


};
int main(){
    police p;
    p.start_dp();

    return 0;
}