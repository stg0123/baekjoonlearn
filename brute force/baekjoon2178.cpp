#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
class maps{
    private:
        vector<vector<char>> map;
        int N,M;
        int min;
    public:
        maps(int n,int m):N(n),M(m){
            map.resize(N);
            for(int i=0;i<N;i++)
                map[i].resize(M,false);

        };
        
        void set_map(){
            for(int i=0;i<N;i++)
                for(int j=0;j<M;j++)
                   std::cin >> map[i][j];
            min=N*M+1;
        };
        int remin(){
            return min;
        };
        void min_set(int n){
            min =n;
        };
        int reN(){
            return N;
        };
        int reM(){
            return M;
        };
        bool reval(int x,int y){
            return map[x][y]-48;
        };
};
class location{
    public:
        int x,y;
        int degree;
};

void bfs(maps& map,int x,int y ,vector<vector<bool>>& visit){
    queue<location> q;
    location l;
    l.x=x;
    l.y=y;
    l.degree=1;
    q.push(l);
    while(q.empty()!=true){
        x=q.front().x;
        y=q.front().y;
        //std::cout << "x =" << x << "y = "<<y<< '\n';
        if(x==(map.reN()-1)&&y==(map.reM()-1)){
            if(map.remin()>q.front().degree)
                map.min_set(q.front().degree);
        }
        else if(map.reval(x,y)==true&&visit[x][y]==false){
            visit[x][y]=true;
            for(int i=0;i<4;i++)
                if(x+dx[i]>=0&&x+dx[i]<map.reN()&&y+dy[i]>=0&&y+dy[i]<map.reM()){
                    location tmp;
                    tmp.x=x+dx[i];
                    tmp.y=y+dy[i];
                    tmp.degree=q.front().degree+1;
                    q.push(tmp);
                }
        }
        q.pop();
    }
}
void dfs(maps & map,int x,int y,int &count,vector<vector<bool>>& visit){
    count++;
    if(map.reval(x,y)==false||visit[x][y]==true){
        count--;
        return;
    }
    visit[x][y]=true;
    if(x==(map.reN()-1)&&y==(map.reM()-1)){
        if(count<map.remin())
            map.min_set(count);
    }
    for(int i=0;i<4;i++){
        if(x+dx[i]>=0&&x+dx[i]<map.reN()&&y+dy[i]>=0&&y+dy[i]<map.reM())
            dfs(map,x+dx[i],y+dy[i],count,visit);
    }
    count --;
    return ;
};

int main(){
    int N,M,count=0;
    std::cin >> N>>M;
    maps map(N,M);
    map.set_map();
    vector<vector<bool>> visit(N,vector<bool>(M,false));
    bfs(map,0,0,visit);
    std::cout << map.remin();

    return 0;
}