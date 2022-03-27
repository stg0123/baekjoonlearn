#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
class labatory{
private:
    vector<vector<int>> map;
    vector<pair<int,int>> virus;
    int N,M,CNT;
public:
    labatory(){
        std::cin >> N >> M;
        map.resize(N,vector<int>(N));
        CNT=N*N;
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                std::cin >> map[i][j];
                if(map[i][j]==1)
                    CNT--;
                if(map[i][j]==2)
                    virus.push_back({i,j});
            }
        }
    }
    int bfs(vector<bool>& check){
        vector<vector<int>> visit(N,vector<int>(N,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<check.size();i++){
            if(check[i]){
                q.push(virus[i]);
                visit[virus[i].first][virus[i].second]=0;
            }
        }
        int count=0,MAX=0;
        pair<int,int> cur;
        int nx,ny;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            count++;
            MAX=max(MAX,visit[cur.first][cur.second]);
            for(int i=0;i<4;i++){
                nx= cur.first+dx[i],ny=cur.second+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<N){
                    if(visit[nx][ny]==-1 && map[nx][ny]!=1){
                        visit[nx][ny]=visit[cur.first][cur.second]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        if(count == CNT)
            return MAX;
        return N*N;
    }
    void find_sol(){
        vector<bool> check(virus.size(),false);
        for(int i=0;i<M;i++)
            check[i]=true;
        int sol = N*N;
        do{
            sol=min(sol,bfs(check));
        }while(prev_permutation(check.begin(),check.end()));
        if(sol==N*N)
            std::cout << -1 <<'\n';
        else
            std::cout << sol << '\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    labatory lb;
    lb.find_sol();

    return 0;
}