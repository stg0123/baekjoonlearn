#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
class rgbfs{
private:
    int N;
    vector<string> map;
    vector<vector<bool>> visit;
public:
    rgbfs(){
        std::cin >> N;
        map.resize(N);
        visit.resize(N,vector<bool>(N,false));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++){
            std::cin >> map[i];
        }
    }
    void rg_bfs(int x,int y){
        queue<pair<int,int>> q;
        visit[x][y]=true;
        q.push({x,y});
        pair<int,int> tmp;
        int nx,ny;
        while(!q.empty()){
            tmp =q.front();
            q.pop();
            for(int i=0;i<4;i++){
                nx=tmp.first+dx[i],ny=tmp.second+dy[i];
                if(nx>=0&&nx<N&&ny>=0&&ny<N){
                    if((map[tmp.first][tmp.second]=='R'||map[tmp.first][tmp.second]=='G')&&map[nx][ny]=='B')
                        continue;
                    if(map[tmp.first][tmp.second]=='B'&&map[tmp.first][tmp.second]!=map[nx][ny])
                        continue;
                    if(!visit[nx][ny]){
                        visit[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    void bfs(int x,int y){
        queue<pair<int,int>> q;
        visit[x][y]=true;
        q.push({x,y});
        pair<int,int> tmp;
        int nx,ny;
        while(!q.empty()){
            tmp =q.front();
            q.pop();
            for(int i=0;i<4;i++){
                nx=tmp.first+dx[i],ny=tmp.second+dy[i];
                if(nx>=0&&nx<N&&ny>=0&&ny<N){
                    if(map[tmp.first][tmp.second]!=map[nx][ny])
                        continue;
                    if(!visit[nx][ny]){
                        visit[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    void find_sol(){
        int sol =0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!visit[i][j]){
                    bfs(i,j);
                    sol++;
                }
            }
        }
        std::cout << sol <<' ';
        sol=0;
        visit.clear();
        visit.resize(N,vector<bool>(N,false));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(!visit[i][j]){
                    rg_bfs(i,j);
                    sol++;
                }
            }
        }
        std::cout << sol;
    }

};
int main(){
    rgbfs rgb;
    rgb.find_sol();
    return 0;
}