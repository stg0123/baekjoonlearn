#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={-1,0,1,1};
int dy[4]={1,1,1,0};
class omok{
private:
    vector<vector<int>> map;
    vector<vector<vector<bool>>> visit;
    int N = 19;
public:
    omok(){
        map.resize(N,vector<int>(N));
        visit.resize(N,vector<vector<bool>>(N,vector<bool>(4,false)));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                std::cin >> map[i][j];
    }

    bool bfs(int x,int y,int sp){
        visit[x][y][sp]=true;
        queue<pair<int,int>> q;
        q.push({x,y});
        int count =0;
        pair<int,int> cur;
        int nx,ny;
        while(!q.empty()){
            cur = q.front();
            q.pop();

            count++;
        
            nx=cur.first+dx[sp],ny=cur.second+dy[sp];
            if(nx>=0 && nx<N && ny>=0 && ny<N){
                if(!visit[nx][ny][sp] && map[nx][ny]==map[cur.first][cur.second]){
                    visit[nx][ny][sp]=true;
                    q.push({nx,ny});
                }
            }
        }
        if(count==5)
            return true;
        return false;
    }
    void find_sol(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int l=0;l<4;l++){
                    if(!visit[j][i][l] && map[j][i]){
                        if(bfs(j,i,l)){
                            std::cout << map[j][i] << '\n';
                            std::cout << j+1 << ' ' << i+1 <<'\n';
                            return ;
                        }
                    }
                }
            }
        }
        std::cout << 0 << '\n';
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    omok ok;
    ok.find_sol();


    return 0;
}