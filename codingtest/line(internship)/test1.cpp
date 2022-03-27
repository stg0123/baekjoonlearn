#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
class test1{
private:
    vector<string> seat;
    int N;
public:
    test1(vector<string> s):seat(s){
        N=s.size();
    }
    int distance(pair<int,int> loc1,pair<int,int> loc2){
        return abs(loc1.first-loc2.first)+abs(loc1.second-loc2.second);
    }

    int bfs(pair<int,int> start){
        queue<pair<int,int>> q;
        vector<vector<bool>> visit(N,vector<bool>(N,false));
        q.push(start);
        visit[start.first][start.second]=true;
        pair<int,int> cur;
        int nx,ny,dis;
        int sol=0;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            dis = distance(start,cur);
            if((seat[cur.first][cur.second]=='M' && dis<=2) || (seat[cur.first][cur.second]=='N' && dis<=3)){
                sol++;
                seat[cur.first][cur.second]='O';
            }
            if(dis==3)
                continue ;
            for(int i=0;i<4;i++){
                nx = cur.first+dx[i],ny = cur.second+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<N){
                    if(!visit[nx][ny]){
                        visit[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return sol;

    }
    int find_sol(){
        int sol=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(seat[i][j]=='C')
                    sol+=bfs({i,j});
            }
        } 
        return sol;


    }



};
int main(){

    return 0;
}