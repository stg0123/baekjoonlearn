#include <iostream>
#include <vector>
#define INF 100000000
using namespace std;
class TSP{
private:
    vector<bool> visit;
    vector<vector<int>> map;
    int N,start;
public:
    TSP(){
        std::cin >>N;
        visit.resize(N+1,false);
        map.resize(N+1,vector<int>(N+1));
        set_val();
        start=1;
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
                std::cin >> map[i][j];
    }
    void start_dfs(){

        visit[start]=true;
        std::cout << dfs(start,1);
    }
    int dfs(int cur,int deg){
        if(deg==N){
            if(map[cur][start])
                return map[cur][start];
            else
                return INF;
        }
        int sol=INF;
        for(int i=1;i<=N;i++){
            if(visit[i]==false&&map[cur][i]){
                visit[i]=true;
                sol=min(sol,dfs(i,deg+1)+map[cur][i]);    
                visit[i]=false;
            }
        }
        return sol;
    }
    

};
int main(){
    TSP tsp;
    tsp.start_dfs();

    return 0;
}
