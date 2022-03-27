#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
struct balls{
    int depth;
    int rx,ry,bx,by;
};
class escape{
private:
    vector<vector<int>> map;
    int N,M;
    pair<int,int> Blue,Red,Holl;
public:
    escape(){
        std::cin >> N >> M;
        map.resize(N,vector<int>(M,0));        
        set_val();
    }
    void set_val(){
        string str;
        for(int i=0;i<N;i++){
            std::cin >> str;
            for(int j=0;j<M;j++){
                switch (str[j]){
                    case '#':
                        map[i][j]=1;
                        break;
                    case 'O':
                        Holl={i,j};
                        map[i][j]=2;
                        break;
                    case 'R':
                        Red={i,j};
                        break;
                    case 'B':
                        Blue={i,j};
                        break;
                }
            }
        }
    }
    void move(pair<int,int>& loc,int i){
        while(1){
            loc.first+=dx[i];
            loc.second+=dy[i];
            if(map[loc.first][loc.second]== 1){
                loc.first-=dx[i];
                loc.second-=dy[i];
                break;
            }
            else if(map[loc.first][loc.second]==2)
                break;
        }
    }
    void bfs(){
        bool visit[10][10][10][10]={};
        queue<balls> q;
        q.push({0,Red.first,Red.second,Blue.first,Blue.second});
        visit[Red.first][Red.second][Blue.first][Blue.second]=true;
        balls cur;
        int sol=-1;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur.depth>10)
                break;
            if(cur.rx == Holl.first && cur.ry == Holl.second){
                sol =cur.depth;
                break;
            }
            for(int i=0;i<4;i++){
                pair<int,int> R = {cur.rx,cur.ry};
                pair<int,int> B = {cur.bx,cur.by};
                move(R,i);
                move(B,i);
                // std::cout << "Depth : "<<cur.depth << ' ';
                // std::cout << "R : " <<R.first << ',' << R.second << ' ';
                // std::cout << "B : " <<B.first << ',' << B.second << ' ';
                if(B==Holl)
                    continue;
                if(R==B){
                    switch (i){
                        case 0:
                            cur.rx < cur.bx ? R.first-- : B.first--;
                            break;
                        case 1:
                            cur.ry < cur.by ? R.second-- : B.second--;
                            break;
                        case 2:
                            cur.rx < cur.bx ? B.first++ : R.first++;
                            break;
                        case 3:
                            cur.ry < cur.by ? B.second++ : R.second++;
                            break;
                    }
                }
                if(!visit[R.first][R.second][B.first][B.second]){
                    q.push({cur.depth+1,R.first,R.second,B.first,B.second});
                    visit[R.first][R.second][B.first][B.second]=true;
                }
            }
        }
        std::cout << sol << '\n';
    }
};
int main(){
    escape ec;
    ec.bfs();
    return 0;
}