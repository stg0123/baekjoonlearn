#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
struct node{
    int x,y,dis;
};
class castle{
private:
    vector<vector<int>> map;
    int N,M,D;
public:
    castle(){
        std::cin >> N >> M >>D;
        map.resize(N,vector<int>(M));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                std::cin >> map[i][j];
    }
    int bfs(vector<bool>& start){
        vector<vector<int>> tmp_map=map;
        int sol =0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(start[j]){
                    vector<vector<bool>> visit(N,vector<bool>(M,false));
                    queue<node> q;
                    q.push({N,j,0});
                    node cur;
                    int nx,ny;
                    while(!q.empty()){
                        cur =q.front();
                        q.pop();
                        if(cur.x<N){
                            if(tmp_map[cur.x][cur.y]){
                                tmp_map[cur.x][cur.y]=2;
                                break;
                            }
                        }
                        for(int l=0;l<4;l++){
                            nx=cur.x+dx[l],ny=cur.y+dy[l];
                            if(nx>=0 && nx<N && ny>=0 && ny<M){
                                if(!visit[nx][ny]&&cur.dis<D){
                                    visit[nx][ny]=true;
                                    q.push({nx,ny,cur.dis+1});
                                }
                            }
                        }
                    }
                }
            }
            for(int l=N-1;l>=0;l--){
                for(int k=0;k<M;k++){
                    if(tmp_map[l][k]==2){
                        sol++;
                        tmp_map[l][k]=0;
                    }
                    if(l!=N-1)
                        tmp_map[l+1][k]=tmp_map[l][k];
                    if(l==0)
                        tmp_map[l][k]=0;
                }
            }
        }
        return sol;
    }
    void find_sol(){
        vector<bool> start(M,false);
        int sol=0;
        for(int i=0;i<3;i++)
            start[i]=1;
        do{
            sol=max(sol,bfs(start));

        }while(prev_permutation(start.begin(),start.end()));
        std::cout << sol << '\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    castle ct;
    ct.find_sol();
    return 0;
}