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
    }
};
class zelda{
private:
    vector<vector<int>> map;
    vector<vector<int>> dp;
    int N;
public:
    zelda(int n):N(n){
        map.resize(N,vector<int>(N));
        dp.resize(N,vector<int>(N,N*N*10));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                std::cin >> map[i][j];   
    }
    void dijkstra(){
        priority_queue<_node,vector<_node>,compare> pq;
        dp[0][0]=map[0][0];
        pq.push({0,0,map[0][0]});
        _node cur;
        int nx,ny;
        while(!pq.empty()){
            cur=pq.top();
            pq.pop();
            if(dp[cur.x][cur.y]<cur.dis)
                continue;
            for(int i=0;i<4;i++){
                nx=cur.x+dx[i],ny=cur.y+dy[i];
                if(nx>=0&&nx<N&&ny>=0&&ny<N){
                    if(dp[nx][ny]>cur.dis+map[nx][ny]){
                        dp[nx][ny]=cur.dis+map[nx][ny];
                        pq.push({nx,ny,dp[nx][ny]});
                    }
                }
            }
        }
        std::cout << dp[N-1][N-1] <<'\n';
    }

};
int main(){
    int n,i=0;
    while(1){
        i++;
        std::cin >> n;
        if(!n)
            break;
        zelda zd(n);
        std::cout << "Problem "<< i <<": ";
        zd.dijkstra();
    }

    return 0;
}