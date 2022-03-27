#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int INF = 2000000000;
struct node{
    int x,y,direction,mirror;
};
struct compare{
    bool operator()(node& a,node& b){
        return a.mirror>b.mirror;
    }
};
class layzer{
private:
    vector<string> map;
    vector<pair<int,int>> start_end;
    vector<vector<int>> dp;
    int H,W;
public:
    layzer(){
        std::cin >> W >> H ;
        map.resize(H);
        dp.resize(H,vector<int>(W,INF));
        set_val();

    }
    void set_val(){
        for(int i=0;i<H;i++){
            std::cin >> map[i];
            for(int j=0;j<W;j++){
                if(map[i][j]=='C')
                    start_end.push_back({i,j});
            }
        }
    }
    void dijkstra(){
        queue<node> q;
        for(int i=0;i<4;i++){
            q.push({start_end[0].first,start_end[0].second,i,0});
        }
        dp[start_end[0].first][start_end[0].second]=0;
        node cur;
        int nx,ny,nmirror;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                nx=cur.x+dx[i],ny=cur.y+dy[i],nmirror=cur.mirror;
                if(nx>=0 && nx<H && ny>=0 && ny<W){
                    if(map[nx][ny]=='*') continue;
                    if(cur.direction != i) nmirror++;
                    if(dp[nx][ny]>=nmirror){
                        dp[nx][ny]=nmirror;
                        q.push({nx,ny,i,nmirror});
                    }
                }
            }
        }
        std::cout << dp[start_end[1].first][start_end[1].second]<< '\n';
    }



};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    layzer lz;
    lz.dijkstra();

    return 0;
}