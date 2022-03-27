#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
class escape{
private:
    vector<vector<char>> map;
    queue<pair<int,int>> wq1,wq2,sq1,sq2;
    int N,M;
public:
    escape(){
        std::cin >> N >> M ;
        map.resize(N,vector<char>(M));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                std::cin >> map[i][j];
                if(map[i][j]=='S')
                    sq1.push({i,j});
                if(map[i][j]=='*')
                    wq1.push({i,j});
            }
        }
    }
    void print_map(){
        std::cout << '\n';
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                std::cout << map[i][j] <<' ';
            std::cout << '\n';
        }
    
    }
    bool bfs(){
        pair<int,int> cur;
        int nx,ny;
        while(!sq1.empty()){
            cur=sq1.front();
            sq1.pop();
            if(map[cur.first][cur.second]!='S')
                continue;
            for(int i=0;i<4;i++){
                nx = cur.first+dx[i],ny = cur.second+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<M){
                    if(map[nx][ny]=='.'){
                        map[nx][ny]='S';
                        sq2.push({nx,ny});
                    }
                    if(map[nx][ny]=='D'){
                        return true;
                    }
                }
            }
        }
        while(!wq1.empty()){
            cur =wq1.front();
            wq1.pop();
            for(int i=0;i<4;i++){
                nx=cur.first+dx[i],ny=cur.second+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<M){
                    if(map[nx][ny]=='.' || map[nx][ny]=='S'){
                        map[nx][ny]='*';
                        wq2.push({nx,ny});
                    }
                }
            }
        }
        return false;
    }
    void find_sol(){
        int sol =0;
        while(!bfs()){
            if(sq2.empty()){
                std::cout << "KAKTUS\n";
                return ;
            }
            sol++;
            wq1=wq2;
            sq1=sq2;
            while(!wq2.empty())
                wq2.pop();
            while(!sq2.empty())
                sq2.pop();
        }
        std::cout << sol+1 << '\n';
    }    


};
int main(){
    escape esc;
    esc.find_sol();
    return 0;
}