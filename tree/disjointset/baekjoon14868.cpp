#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
class civilization{
private:
    vector<int> parent;
    queue<pair<int,int>> Q,NQ;
    vector<vector<int>> map;
    int N,M;
    int mergenum=0;
public:
    civilization(){
        std::cin >> N >> M;
        parent.resize(M+1,-1);
        map.resize(N,vector<int>(N,0));
        set_val(); 
    }
    void set_val(){
        int x,y;
        int idx=1;
        int nx,ny;
        for(int i=0;i<M;i++){
            std::cin >> x >> y;
            Q.push({x-1,y-1});
            map[x-1][y-1]=idx;
            for(int j=0;j<4;j++){
                nx=x-1+dx[j],ny=y-1+dy[j];
                if(nx>=0&&nx<N&&ny>=0&&ny<N){
                    if(map[nx][ny]!=0)
                        merge(map[nx][ny],idx);
                }
            }
            idx++;
        }
    }
    void print(){
        std::cout << '\n';
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                std::cout << map[i][j];
            std::cout << '\n';
        }
    }
    int find(int n){
        if(parent[n]==-1)
            return n;
        return parent[n]=find(parent[n]);
    }
    bool merge(int a,int b){
        int p_a=find(a);
        int p_b=find(b);
        if(p_a==p_b)
            return false;
        parent[p_b]=p_a;
        mergenum++;
        return true;
    }
    void bfs(){
        pair<int,int> cur;
        int nx,ny;
        while(!Q.empty()){
            cur =Q.front();
            Q.pop();
            for(int i=0;i<4;i++){
                nx=cur.first+dx[i],ny=cur.second+dy[i];
                if(nx>=0&& nx<N&&ny>=0&&ny<N){
                    if(map[nx][ny]!=0)
                        merge(map[nx][ny],map[cur.first][cur.second]);
                    else{
                        map[nx][ny]=map[cur.first][cur.second];
                        for(int j=0;j<4;j++){
                            if(nx+dx[j]>=0&&nx+dx[j]<N&&ny+dy[j]>=0&&ny+dy[j]<N){
                                if(map[nx+dx[j]][ny+dy[j]]!=0)
                                    merge(map[nx+dx[j]][ny+dy[j]],map[nx][ny]);
                            }
                        }
                        NQ.push({nx,ny});
                    }
                }
            }
        }
    }
    void find_sol(){
        int sol=0;
        while(!(mergenum==M-1)){
            bfs();
            sol++;
            Q=NQ;
            while(!NQ.empty())
                NQ.pop();
        }
        std::cout << sol;
    }
};
int main(){
    civilization cz;
    cz.find_sol();

    return 0;
}