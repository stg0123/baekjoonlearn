#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int INF = 1000000000;
struct node{
    int x,y;
    int depth;
};
class laboratory{
private:
    vector<vector<int>> map;
    vector<pair<int,int>> virus;
    int N,M,goal=0,ans=INF;
public:
    laboratory(){
        std::cin >> N >> M;
        map.resize(N,vector<int>(N));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                std::cin >> map[i][j];
                if(map[i][j]==0)
                    goal++;
                else if(map[i][j]==2)
                    virus.push_back({i,j});
            }
        }
    }
    void bfs(vector<bool>& start){
        vector<vector<int>> visit=map;
        queue<node> q;
        for(int i=0;i<start.size();i++){
            if(start[i]){
                q.push({virus[i].first,virus[i].second,0});
                visit[virus[i].first][virus[i].second]=3;
            }
        }
        int sol=0,g=0;
        node cur;
        int nx,ny;
        while(!q.empty()){
            cur =q.front();
            q.pop();
            if(map[cur.x][cur.y]!=2)
                sol=max(sol,cur.depth);
            for(int i=0;i<4;i++){
                nx=cur.x+dx[i],ny=cur.y+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<N){
                    if(!visit[nx][ny] || visit[nx][ny]==2){
                        if(!visit[nx][ny])
                            g++;
                        visit[nx][ny]=3;
                        q.push({nx,ny,cur.depth+1});
                    }
                }
            }
        }
        if(g==goal)
            ans=min(ans,sol);
    }
    void find_sol(){
        vector<bool> start(virus.size(),false);
        for(int i=0;i<M;i++)
            start[i]=true;
        do{
            bfs(start);
        }while(prev_permutation(start.begin(),start.end()));
        if(ans == INF)
            std::cout << -1 << '\n';
        else
            std::cout << ans << '\n';
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    laboratory lb;
    lb.find_sol();   
    return 0;
}