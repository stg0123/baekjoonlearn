#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
class cheese{
private:
    vector<vector<int>> map; // 사용 -1 미사용 0 치즈 1 주변 +1
    int N,M,sol=0;
    queue<pair<int,int>> q1,q2;
public:
    cheese(){
        std::cin >> N >> M;
        map.resize(N,vector<int>(M));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                std::cin >> map[i][j];
        q1.push({0,0});
    }
    bool bfs(){
        pair<int,int> cur;
        int nx,ny;
        while(!q1.empty()){
            cur = q1.front();
            q1.pop();

            for(int i=0;i<4;i++){
                nx=cur.first+dx[i],ny=cur.second+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<M){
                    if(map[nx][ny]==0){
                        map[nx][ny]=-1;
                        q1.push({nx,ny});
                    }
                    else if(map[nx][ny]==1){
                        map[nx][ny]++;
                    }
                    else if(map[nx][ny]==2){
                        map[nx][ny]=-1;
                        q2.push({nx,ny});
                    }
                }
            }
        }
        if(q2.empty()){
            return false;
        }
        else{
            q1=q2;
            while(!q2.empty())
                q2.pop();
            return true;
        }
    }
    void find_sol(){
        while(bfs())
            sol++;
        std::cout << sol <<'\n';
    }
};
int main(){
    cheese ch;
    ch.find_sol();

    return 0;
}