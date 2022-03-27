#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
struct _node{
    int depth;
    int x,y;
};
struct compare{
    bool operator()(_node& a,_node& b){
        if(a.depth==b.depth)
            return a.x == b.x ? a.y>b.y : a.x>b.x;
        else
            return a.depth> b.depth;
    };
};
class shark{
private:
    vector<vector<int>> map;
    int N;
    pair<int,int> s_loc;
    int level=2;
    int exp=0;
public:
    shark(){
        std::cin >> N;
        map.resize(N,vector<int>(N));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                std::cin >> map[i][j];
                if(map[i][j]==9){
                    s_loc={i,j};
                    map[i][j]=0;
                }   
            }
        }
    }
    int bfs(){
        vector<vector<bool>> visit(N,vector<bool>(N,false));
        priority_queue<_node,vector<_node>,compare> q;
        q.push({0,s_loc.first,s_loc.second});
        visit[s_loc.first][s_loc.second]=true;
        _node cur;
        int nx,ny;
        while(!q.empty()){
            cur = q.top();
            q.pop();
            if(map[cur.x][cur.y] && map[cur.x][cur.y]<level){
                s_loc={cur.x,cur.y};
                map[cur.x][cur.y]=0;
                if(++exp==level){
                    exp=0;
                    level++;
                }
                return cur.depth;
            }
            for(int i=0;i<4;i++){
                nx=cur.x+dx[i],ny=cur.y+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<N){
                    if(!visit[nx][ny]){
                        visit[nx][ny]=true;
                        if(map[nx][ny]<=level)
                            q.push({cur.depth+1,nx,ny});
                    }
                }
            }
        }
        return 0;
    }
    void find_sol(){
        int sol=0,tmp;
        while(true){
            tmp=bfs();
            if(tmp)
                sol+=tmp;
            else
                break;
        }
        std::cout << sol<<"\n";
    }
};  

int main(){
    shark sh;
    sh.find_sol();

    return 0;
}