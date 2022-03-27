#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,1,-1};
struct _node{
    int depth;
    int x,y;
};
class shark2{
private:
    vector<vector<int>> map;
    int N,M;
    int MAX=0;
public:
    shark2(){
        std::cin >> N >> M;
        map.resize(N,vector<int>(M));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                std::cin >> map[i][j];
    }
    void bfs(int x,int y){
        vector<vector<bool>> visit(N,vector<bool>(M,false));
        queue<_node> q;
        q.push({0,x,y});
        visit[x][y]=true;
        _node cur;
        int nx,ny;
        while(!q.empty()){
            cur =q.front();
            q.pop();
            if(map[cur.x][cur.y]){
                MAX=max(cur.depth,MAX);
                return ;
            }
            for(int i=0;i<8;i++){
                nx=cur.x+dx[i],ny=cur.y+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<M){
                    if(!visit[nx][ny]){
                        visit[nx][ny]=true;
                        q.push({cur.depth+1,nx,ny});
                    }
                }
            }
        }
    }
    void find_sol(){
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(!map[i][j])
                    bfs(i,j);
        std::cout << MAX <<'\n';
    }

};
int main(){
    shark2 sh;
    sh.find_sol();
    return 0;
}