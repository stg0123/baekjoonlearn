#include <iostream>
#include <vector>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
class ice_mountain{
private:
    vector<vector<vector<int>>> map;
    vector<vector<bool>> visit;
    int N,M;
    int z_num=0;
public:
    ice_mountain(){
        std::cin >> N >> M;
        map.resize(2);
        map[0].resize(N,vector<int>(M,0));
        map[1].resize(N,vector<int>(M,0));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                std::cin >> map[0][i][j];
                if(map[0][i][j]==0)
                    z_num++;
            }
        }
    }
    void dfs(int x,int y,int idx){
        int nx,ny;
        int tmp=0;
        for(int i=0;i<4;i++){
            nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<M){
                if(map[idx][nx][ny]==0)
                    tmp++;
            }
        }
        map[(idx+1)%2][x][y]=(map[idx][x][y]-tmp) <0 ? 0 :(map[idx][x][y]-tmp);
        for(int i=0;i<4;i++){
            nx=x+dx[i],ny=y+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<M){
                if(!visit[nx][ny]&&map[idx][nx][ny]>0){
                    visit[nx][ny]=true;
                    dfs(nx,ny,idx);
                }
            }
        }
    }
    void find_sol(){
        if(z_num==0){
            std::cout<<0;
            return ;
        }
        int idx=0,sol;
        while(1){
            visit.clear();
            visit.resize(N,vector<bool>(M,false));
            map[(idx+1)%2].clear();
            map[(idx+1)%2].resize(N,vector<int>(M,0));
            sol=0;
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    if(!visit[i][j]&&map[idx%2][i][j]>0){
                        visit[i][j]=true;
                        dfs(i,j,idx%2);
                        sol++;
                    }
                }
            }
            if(sol==0){
                std::cout << 0;
                break;
            }
            if(sol>1){
                std::cout <<idx;
                break;
            }
            idx++;
        }
    }

};
int main(){
    ice_mountain im;
    im.find_sol();

    return 0;
}