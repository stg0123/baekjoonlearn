#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
class yang{
private:
    vector<vector<char>> map;
    int R,C;
    vector<vector<bool>> visit;
    int S=0,W=0;
public:
    yang(){
        std::cin >> R >>C;
        map.resize(R,vector<char>(C));
        visit.resize(R,vector<bool>(C,false));
        set_val();
    }
    void set_val(){
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                std::cin >> map[i][j];
                if(map[i][j]=='v')
                    W++;
                else if(map[i][j]=='o')
                    S++;
            }
        }
    }
    void bfs(int x,int y){
        queue<pair<int,int>> q;
        q.push({x,y});
        visit[x][y]=true;
        pair<int,int> cur;
        int nx,ny;
        int o_cnt=0,v_cnt=0;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(map[cur.first][cur.second]=='v')
                v_cnt++;
            else if(map[cur.first][cur.second]=='o')
                o_cnt++;

            for(int i=0;i<4;i++){
                nx=cur.first+dx[i],ny=cur.second+dy[i];
                if(nx>=0 && nx<R && ny>=0 && ny<C){
                    if(!visit[nx][ny] && map[nx][ny]!='#'){
                        visit[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
        }
        if(o_cnt>v_cnt)
            W-=v_cnt;
        else
            S-=o_cnt;
    }
    void find_sol(){
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(!visit[i][j] && (map[i][j]=='v' || map[i][j]=='o'))
                    bfs(i,j);
            }
        }
        std::cout << S <<' '<< W <<'\n';
    }

};
int main(){
    yang yg;
    yg.find_sol();

    return 0;
}