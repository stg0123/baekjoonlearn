#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct node{
    int x,y;
    int depth;
};
class present{
private:
    vector<vector<bool>> map;
    int N,M;
public:
    present(){
        std::cin >> N >> M;
        map.resize(N,vector<bool>(M));
        set_val();
    }
    void set_val(){
        char ch;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                std::cin >> ch;
                if(ch == 'W')
                    map[i][j]=0;
                else
                    map[i][j]=1;
            }
        }
    }
    int bfs(pair<int,int> start){
        queue<node> q;
        q.push({start.first,start.second,0});
        vector<vector<bool>> visit=map;
        visit[start.first][start.second]=0;
        node cur;
        int nx,ny;
        int sol=0;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            sol=max(sol,cur.depth);
            for(int i=0;i<4;i++){
                nx=cur.x+dx[i],ny=cur.y+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<M){
                    if(visit[nx][ny]){
                        visit[nx][ny]=0;
                        q.push({nx,ny,cur.depth+1});
                    }
                }
            }
        }
        return sol;
    }
    void find_sol(){
        int sol=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j])
                    sol=max(sol,bfs({i,j})); 
            }
        }
        std::cout << sol << '\n';
    }


};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    present pt;
    pt.find_sol();   
    return 0;
}