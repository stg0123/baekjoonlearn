#include <iostream>
#include <vector>
using namespace std;
int INF=1000000000;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
class watch{
private:
    vector<vector<int>> map;
    vector<pair<int,int>> loc;
    int N,M;
    int size=0;
    int sol= INF;
public:
    watch(){
        std::cin >> N >> M;
        map.resize(N,vector<int>(M,0));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                std::cin >> map[i][j];
                if(!map[i][j])
                    size++;
                else if(map[i][j]&&map[i][j]!=6)
                    loc.push_back({i,j});
            }
        }
    }
    void dfs(int depth,int cur,vector<vector<int>> cur_map){
        if(depth == loc.size()){
            sol = min(size-cur,sol);
            return ;
        }
        if(map[loc[depth].first][loc[depth].second]==1){
            for(int i=0;i<4;i++){
                vector<vector<int>> tmp=cur_map;
                int x=loc[depth].first;
                int y=loc[depth].second;
                int ncur=cur;
                while(1){
                    x+=dx[i],y+=dy[i];
                    if(x>=0 && x<N && y>=0 && y<M){
                        if(tmp[x][y]==0){
                            tmp[x][y]=-1;
                            ncur++;
                        }
                        else if(tmp[x][y]==6)
                            break;
                    }
                    else
                        break;
                }
                dfs(depth+1,ncur,tmp);
            }
        }
        else if(map[loc[depth].first][loc[depth].second]==2){
            for(int i=0;i<2;i++){
                vector<vector<int>> tmp=cur_map;
                int ncur=cur;
                int x=loc[depth].first;
                int y=loc[depth].second;
                while(1){
                    x+=dx[i],y+=dy[i];
                    if(x>=0 && x<N && y>=0 && y<M){
                        if(tmp[x][y]==0){
                            tmp[x][y]=-1;
                            ncur++;
                        }
                        else if(tmp[x][y]==6)
                            break;
                    }
                    else
                        break;
                }
                x=loc[depth].first;
                y=loc[depth].second;
                while(1){
                    x+=dx[i+2],y+=dy[i+2];
                    if(x>=0 && x<N && y>=0 && y<M){
                        if(tmp[x][y]==0){
                            tmp[x][y]=-1;
                            ncur++;
                        }
                        else if(tmp[x][y]==6)
                            break;
                    }
                    else
                        break;
                }
                dfs(depth+1,ncur,tmp);
            }
        }
        else if(map[loc[depth].first][loc[depth].second]==3){
            for(int i=0;i<4;i++){
                vector<vector<int>> tmp=cur_map;
                int ncur=cur;
                int x=loc[depth].first;
                int y=loc[depth].second;
                while(1){
                    x+=dx[i],y+=dy[i];
                    if(x>=0 && x<N && y>=0 && y<M){
                        if(tmp[x][y]==0){
                            tmp[x][y]=-1;
                            ncur++;
                        }
                        else if(tmp[x][y]==6)
                            break;
                    }
                    else
                        break;
                }
                x=loc[depth].first;
                y=loc[depth].second;
                while(1){
                    x+=dx[(i+1)%4],y+=dy[(i+1)%4];
                    if(x>=0 && x<N && y>=0 && y<M){
                        if(tmp[x][y]==0){
                            tmp[x][y]=-1;
                            ncur++;
                        }
                        else if(tmp[x][y]==6)
                            break;
                    }
                    else
                        break;
                }
                dfs(depth+1,ncur,tmp);
            }
        }
        else if(map[loc[depth].first][loc[depth].second]==4){
            for(int i=0;i<4;i++){
                vector<vector<int>> tmp=cur_map;
                int ncur=cur;
                int x=loc[depth].first;
                int y=loc[depth].second;
                while(1){
                    x+=dx[i],y+=dy[i];
                    if(x>=0 && x<N && y>=0 && y<M){
                        if(tmp[x][y]==0){
                            tmp[x][y]=-1;
                            ncur++;
                        }
                        else if(tmp[x][y]==6)
                            break;
                    }
                    else
                        break;
                }
                x=loc[depth].first;
                y=loc[depth].second;
                while(1){
                    x+=dx[(i+1)%4],y+=dy[(i+1)%4];
                    if(x>=0 && x<N && y>=0 && y<M){
                        if(tmp[x][y]==0){
                            tmp[x][y]=-1;
                            ncur++;
                        }
                        else if(tmp[x][y]==6)
                            break;
                    }
                    else
                        break;
                }
                x=loc[depth].first;
                y=loc[depth].second;
                while(1){
                    x+=dx[(i+2)%4],y+=dy[(i+2)%4];
                    if(x>=0 && x<N && y>=0 && y<M){
                        if(tmp[x][y]==0){
                            tmp[x][y]=-1;
                            ncur++;
                        }
                        else if(tmp[x][y]==6)
                            break;
                    }
                    else
                        break;
                }
                dfs(depth+1,ncur,tmp);
            }
        }
        else{
            vector<vector<int>> tmp=cur_map;
            int x;
            int y;
            int ncur=cur;
            for(int i=0;i<4;i++){
                x=loc[depth].first;
                y=loc[depth].second;
                while(1){
                    x+=dx[i],y+=dy[i];
                    if(x>=0 && x<N && y>=0 && y<M){
                        if(tmp[x][y]==0){
                            tmp[x][y]=-1;
                            ncur++;
                        }
                        else if(tmp[x][y]==6)
                            break;
                    }
                    else
                        break;
                }
            }
            dfs(depth+1,ncur,tmp);
        }
    }
    void find_sol(){
        dfs(0,0,map);
        std::cout << sol << '\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    watch wt;
    wt.find_sol();

    return 0;
}