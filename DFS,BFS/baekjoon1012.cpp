#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};
typedef struct loc{
    int x,y;
}loc;
class maps{
    private:
        vector<vector<bool>> map;
        int M,N;
    public:
        maps(int m,int n):M(m),N(n){
            map.resize(N);
            for(int i=0;i<N;i++)
                map[i].resize(M,false);
            
            return ;
        };
        ~maps(){
            map.clear();
            return ;
        }
        void mapcheck(int K){
            for(int i=0;i<K;i++){
                int a,b;
                std::cin >> a>>b;
                map[b][a]=true;
            }
            return ;
        };
        bool reval(int x,int y){
            return map[x][y];
        };
        int reM(){
            return M;
        };
        int reN(){
            return N;
        };
};

int bfs(maps& map ,int x,int y,vector<vector<bool>>& visit){
    if(visit[x][y]==true||map.reval(x,y)==false)
        return 0;
    int count =0;
    loc lo;
    lo.x=x;
    lo.y=y;
    queue<loc> q;
    q.push(lo);
    while(q.empty()!=true){
        x=q.front().x;
        y=q.front().y;
        if(visit[x][y]==false&&map.reval(x,y)==true){
            visit[x][y] =true;
            count++;
            for(int i=0;i<4;i++)
                if(x+dx[i]>=0&&x+dx[i]<map.reN()&&y+dy[i]>=0&&y+dy[i]<map.reM()){
                    loc lotmp;
                    lotmp.x=x+dx[i];
                    lotmp.y=y+dy[i];
                    q.push(lotmp);
                }
        }
        q.pop();
    }
    return count;
};

int main(){
    int re;
    std::cin >> re;
    int M,N,K;
    vector<vector<bool>> visit;
    for(int re1=0;re1<re;re1++){    
        std::cin>> M>>N  >> K;
        visit.resize(N);
        for(int i=0;i<N;i++)
            visit[i].resize(M,false);
        maps map(M,N);
        map.mapcheck(K);
        int count=0;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                int a=bfs(map,i,j,visit);
                if(a>0)
                    count++;
            }
        std::cout<<count<<'\n';
        for(int i=0;i<N;i++)
            visit[i].clear();
        visit.clear();
        //map.~maps();
    }
    return 0;
}