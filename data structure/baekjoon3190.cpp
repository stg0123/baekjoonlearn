#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
class snake{
private:
    vector<vector<int>> map;
    queue<pair<int,char>> qry;
    int N;
public:
    snake(){
        std::cin >> N ;
        map.resize(N,vector<int>(N,0));
        set_val();
    }
    void set_val(){
        int n,a,b;
        char ch;
        std::cin >> n;
        for(int i=0;i<n;i++){
            std::cin >>a >> b;
            map[a-1][b-1]=1;
        }
        map[0][0]=2;
        std::cin >> n;
        for(int i=0;i<n;i++){
            std::cin >>a >>ch;
            qry.push({a,ch});
        }
    }
    void find_sol(){
        int sol=0,idx=0;
        deque<pair<int,int>> dq;
        dq.push_back({0,0});
        pair<int,int> cur;
        int nx,ny;
        while(1){
            sol++;
            cur=dq.back();
            nx=cur.first+dx[idx],ny=cur.second+dy[idx];
            if(nx>=0 && nx<N && ny>=0 && ny<N){
                dq.push_back({nx,ny});
                if(map[nx][ny]==2)
                    break;
                if(map[nx][ny]==0){
                    map[dq.front().first][dq.front().second]=0;
                    dq.pop_front();
                }
                map[nx][ny]=2;
            }
            else
                break;
            if(qry.front().first==sol){
                if(qry.front().second=='L')
                    idx=(idx-1+4)%4;
                else
                    idx=(idx+1)%4;
                qry.pop();
            }
        }
        std::cout << sol << '\n';
        
    }


};
int main(){
    snake sn;
    sn.find_sol();
    return 0;
}