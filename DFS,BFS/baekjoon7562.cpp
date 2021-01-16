#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};
struct node {
    pair<int,int> loc;
    int degree;
    
};
class knight{
private:
    vector<vector<bool>> visit;
    int N;
    pair<int,int> start,end;
public:
    knight(int n):N(n){
        visit.resize(n);
        for(int i=0;i<n;i++)
            visit[i].resize(n,false);
    };

    void set_val(){
        std::cin >>start.first >> start.second;
        std::cin >>end.first>>end.second;

    };

    void BFS(){
        queue<node> q;
        visit[start.first][start.second]=true;
        node tmp;
        tmp.loc=start;
        tmp.degree=0;
        q.push(tmp);
        int x,y,deg;
        while(!q.empty()){
            x=q.front().loc.first;
            y=q.front().loc.second;
            deg=q.front().degree;
            q.pop();
            if(x==end.first&&y==end.second){
                std::cout << deg<<'\n';
                break;
            }
            for(int i=0;i<8;i++){
                if(x+dx[i]>=0&&x+dx[i]<N&&y+dy[i]>=0&&y+dy[i]<N&&!visit[x+dx[i]][y+dy[i]]){
                    visit[x+dx[i]][y+dy[i]]=true;
                    tmp.loc.first=x+dx[i];
                    tmp.loc.second=y+dy[i];
                    tmp.degree=deg+1;
                    q.push(tmp);
                }    
            }
        }
    }

};
int main(){
    int n,vol;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> vol;
        knight k(vol);
        k.set_val();
        k.BFS();

    }
    return 0;
}