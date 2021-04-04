#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct _node{
    int x,y,dis;
};
struct compare{
    bool operator()(_node& a,_node& b){
        return a.dis>b.dis;
    };
};
class algo{
private:
    vector<vector<int>> map;
    vector<vector<int>> dp;
    int N,M;
public:
    algo(){
        std::cin >> M >> N;
        map.resize(N,vector<int>(M,0));
        dp.resize(N,vector<int>(M,N*M));
        set_val();
    }
    void set_val(){
        char ch;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                std::cin >> ch;
                if(ch=='1')
                    map[i][j]=1;
            }
        }
    }
    void dijkstra(){
        priority_queue<_node,vector<_node>,compare> pq;
        dp[0][0]=0;
        pq.push({0,0,0});
        _node cur,tmp;
        int nx,ny;
        while(!pq.empty()){
            cur=pq.top();
            pq.pop();
            if(dp[cur.x][cur.y]<cur.dis)
                continue;
            for(int i=0;i<4;i++){
                nx=cur.x+dx[i],ny=cur.y+dy[i];
                if(nx>=0&&nx<N&&ny>=0&&ny<M){
                    if(dp[nx][ny]>cur.dis+map[nx][ny]){
                        dp[nx][ny]=cur.dis+map[nx][ny];
                        pq.push({nx,ny,dp[nx][ny]});
                    }
                }
            }
        }
        std::cout << dp[N-1][M-1];

    }


};
int main(){
    algo ag;
    ag.dijkstra();

    return 0;
}