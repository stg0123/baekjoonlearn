#include <iostream>
#include <vector>
using namespace std;
int INF=1000000000;
class TSP{
private:
    vector<vector<int>> disjoint;
    vector<bool> visit;
    int start=0;
    int N;
public:
    TSP(){
        std::cin >> N;
        disjoint.resize(N,vector<int>(N));
        visit.resize(N,false);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                std::cin >> disjoint[i][j];
    }
    int dfs(int cur,int degree){
        if(degree==N){
            if(disjoint[cur][start])
                return disjoint[cur][start];
            else
                return INF;
        }
        int sol=INF;
        for(int i=0;i<N;i++){
            if(disjoint[cur][i] && !visit[i]){
                visit[i]=true;
                sol=min(sol,disjoint[cur][i]+dfs(i,degree+1));
                visit[i]=false;
            }
        }
        return sol;
    }
    void find_sol(){
        visit[start]=true;
        std::cout << dfs(start,1)<<'\n';
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    TSP tsp;
    tsp.find_sol();
    return 0;
}