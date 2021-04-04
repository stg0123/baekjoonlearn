#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
class kevin{
private:
    vector<vector<int>> path;
    int N,M;
public:
    kevin(){
        std::cin >> N >> M;
        path.resize(N+1);
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a >> b;
            path[a].push_back(b);
            path[b].push_back(a);
        }
    }
    int bfs(int start){
        int result=0,next;
        pair<int,int> cur;
        vector<bool> visit(N+1,false);
        queue<pair<int,int>> q;
        q.push({start,0});
        visit[start]=true;
        while(!q.empty()){
            cur=q.front();
            q.pop();
            result+=cur.second;
            for(int i=0;i<path[cur.first].size();i++){
                next= path[cur.first][i];
                if(!visit[next]){
                    visit[next]=true;
                    q.push({next,cur.second+1});
                }
            }   
        }
        return result;
    }
    void find_sol(){
        int mval=INF,sol,tmp;
        for(int i=1;i<=N;i++){
            tmp=bfs(i);
            if(mval>tmp){
                mval=tmp;
                sol=i;
            }
        }
        std::cout << sol; 
    }  


};
int main(){
    kevin ke;
    ke.find_sol();
    return 0;
}