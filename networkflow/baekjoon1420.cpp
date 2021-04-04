#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define INF 1000000000
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
struct _node{
    int capacity;
    int flow;
};
class school{
private:
    map<pair<int,int>,int> c,f;
    vector<vector<int>> path;
    vector<int> level,work;
    int N,M;
    int START,END=0;
public:
    school(){
        std::cin >> N >> M;
        path.resize(N*M*2);
        level.resize(N*M*2);
        work.resize(N*M*2);
        set_connect();
    }  
    void set_connect(){
        string str;
        vector<string> map;
        for(int i=0;i<N;i++){
            std::cin >> str;
            map.push_back(str);
        }
        int idx,nx,ny;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                idx=i*M+j;
                path[idx].push_back(idx+N*M);
                path[idx+N*M].push_back(idx);
                c[{idx,idx+N*M}]=1;
                for(int l=0;l<2;l++){
                    nx=i+dx[l],ny=j+dy[l];
                    if(nx>=0 && nx<N && ny>=0 && ny<M){
                        if(map[i][j]!='#'&&map[nx][ny]!='#'){
                            path[idx+N*M].push_back(nx*M+ny);
                            path[nx*M+ny].push_back(idx+N*M);

                            path[nx*M+ny+N*M].push_back(idx);
                            path[idx].push_back(nx*M+ny+N*M);
                            
                            c[{nx*M+ny+N*M,idx}]=INF;

                            c[{idx+N*M,nx*M+ny}]=INF;
                        }
                        if(map[i][j]=='K' && map[nx][ny]=='H')
                            END=-1;
                        else if(map[i][j]=='H' && map[nx][ny]=='K')
                            END=-1;
                    }
                }
                if(map[i][j]=='K'){
                    c[{idx,idx+N*M}]=INF;
                    START=idx;
                }
                else if(map[i][j]=='H' && END==0 ){
                    c[{idx,idx+N*M}]=INF;
                    END=idx;
                }
            }
        }
    }
    bool bfs(){
        fill(level.begin(),level.end(),-1);
        level[START]=0;
        queue<int> q;
        q.push(START);
        int cur;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            for(int next : path[cur]){
                if(level[next]==-1 && c[{cur,next}]-f[{cur,next}]>0){
                    level[next]=level[cur]+1;
                    q.push(next);
                }
            }
        }
        return level[END]!=-1;
    }
    int dfs(int cur,int flow){
        if(cur==END)
            return flow;
        int next,tmp;
        for(int& i=work[cur];i<path[cur].size();i++){
            next=path[cur][i];
            if(level[next]==level[cur]+1 && c[{cur,next}]-f[{cur,next}]>0){
                tmp = dfs(next,min(c[{cur,next}]-f[{cur,next}],flow));
                if(tmp>0){
                    f[{cur,next}]+=tmp;
                    f[{next,cur}]-=tmp;
                    return tmp;
                }
            }
        }
        return 0;
    }
    void dinic(){
        if(END==-1){
            std::cout << -1 << '\n';
            return ;
        }
        int sol=0;
        while(bfs()){
            fill(work.begin(),work.end(),0);
            while(1){
                int flow = dfs(START,INF);
                if(flow==0)
                    break;
                sol+=flow;  
            }
        }
        std::cout << sol<<'\n';
    }

};
int main(){
    school sc;
    sc.dinic();

    return 0;
}