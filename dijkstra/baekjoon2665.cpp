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
class makemiro{
private:
    vector<vector<int>> dp;
    vector<vector<int>> map;
    int N;
public:
    makemiro(){
        std::cin >> N;
        map.resize(N,vector<int>(N,0));
        dp.resize(N,vector<int>(N,N*N));
        set_val();
    }
    void set_val(){
        char ch;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                std::cin >> ch;
                if(ch=='0')
                    map[i][j]=1;
            }
        }
    }
    void dijkstra(){
        priority_queue<_node,vector<_node>,compare> pq;
        dp[0][0]=map[0][0];
        pq.push({0,0,dp[0][0]});
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
        std::cout << dp[N-1][N-1];

    }


};
int main(){
    makemiro mk;
    mk.dijkstra();
    return 0;
}