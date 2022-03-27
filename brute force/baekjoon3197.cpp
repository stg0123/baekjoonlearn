#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
class swan{
private:
    queue<pair<int,int>> WQ,WNQ,SWQ,SWNQ;
    vector<vector<char>> map;
    vector<vector<bool>> visit;
    int N,M;
    bool find=false;
public:
    swan(){
        std::cin >> N >> M ;
        map.resize(N,vector<char>(M));
        visit.resize(N,vector<bool>(M,false));
        set_val(); 
    }  
    void set_val(){
        pair<int,int> swan_loc;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                std::cin >> map[i][j];
                if(map[i][j]!='X')
                    WQ.push({i,j});
                if(map[i][j]=='L')
                    swan_loc ={i,j};
            }
        }
        SWQ.push(swan_loc);
        visit[swan_loc.first][swan_loc.second]=true;
    }
    void W_bfs(){
        pair<int,int> cur;
        int nx,ny;
        while(!WQ.empty()){
            cur =WQ.front();
            WQ.pop();
            for(int i=0;i<4;i++){
                nx=cur.first+dx[i],ny=cur.second+dy[i];
                if(nx>=0&&nx<N&&ny>=0&&ny<M){
                    if(map[nx][ny]=='X'){
                        map[nx][ny]='.';
                        WNQ.push({nx,ny});
                    }
                }
            }
        }
    }
    void SW_bfs(){
        pair<int,int> cur;
        int nx,ny;
        while(!SWQ.empty()){
            cur=SWQ.front();
            SWQ.pop();
            for(int i=0;i<4;i++){
                nx=cur.first+dx[i],ny=cur.second+dy[i];
                if(nx>=0&&nx<N&&ny>=0&&ny<M){
                    if(!visit[nx][ny]){
                        visit[nx][ny]=true;
                        if(map[nx][ny]=='.')
                            SWQ.push({nx,ny});
                        else if(map[nx][ny]=='L'){
                            find=true;
                            return ;
                        }
                        else if(map[nx][ny]=='X')
                            SWNQ.push({nx,ny});
                    }
                }
            }
        }
    }
    void find_sol(){
        int day=0;
        while(!find){
            SW_bfs();
            if(!find){
                W_bfs();
                WQ=WNQ;
                SWQ=SWNQ;
                while(!SWNQ.empty())
                    SWNQ.pop();
                while(!WNQ.empty())
                    WNQ.pop();
                day++;
            }
        }
        std::cout << day <<'\n';
    }

};
int main(){
    swan sw;
    sw.find_sol();
    return 0;
}