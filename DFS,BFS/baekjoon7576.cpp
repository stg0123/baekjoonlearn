#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
typedef struct node{
    int dgree;
    pair<int,int> loc;
}node;

class tomato{
    private:
        vector<vector<int>> map;
        vector<pair<int,int>> start;
        int M,N,zero_num;
    public :
        tomato(int m,int n):M(m),N(n){
            map.resize(n);
            for(int i=0;i<n;i++)
                map[i].resize(m,0);
            zero_num=0;
        };

        void set_map(){
            pair<int,int> tmp;
            for(int i=0;i<N;i++)
                for(int j=0;j<M;j++){
                    std::cin >> map[i][j];
                    if(map[i][j]==1){            
                        tmp.first=i;
                        tmp.second=j;
                        start.push_back(tmp);
                    }
                    else if(map[i][j]==0)
                        zero_num+=1;
                }           
        };

        void print_map(){
            std::cout <<'\n';
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++)
                    std::cout << map[i][j]<< ' ';
            std::cout << '\n';
            };
        };

        bool map_check(){
            for(int i=0;i<N;i++)
                for(int j=0;j<M;j++)
                    if(map[i][j]==0)
                        return false;
                        
            return true;
        };

        void bfs(){
            if(map_check()){
                std::cout << 0;
                return ;
            }
            queue<node> q;
            int x,y,deg;
            bool flag=false;
            node tmp;
            for(int i=0;i<start.size();i++){
                tmp.dgree=0;
                tmp.loc=start[i];
                q.push(tmp);
            }
            while(!q.empty()){
                x=q.front().loc.first;
                y=q.front().loc.second;
                deg=q.front().dgree;
                
                for(int i=0;i<4;i++){
                    if(x+dx[i]>=0&&x+dx[i]<N&&y+dy[i]>=0&&y+dy[i]<M&&map[x+dx[i]][y+dy[i]]==0){
                            tmp.dgree=deg+1;
                            tmp.loc.first=x+dx[i];
                            tmp.loc.second=y+dy[i];
                            q.push(tmp);
                            map[x+dx[i]][y+dy[i]]=1;
                            zero_num-=1;
                            if(zero_num==0){
                                flag=true;
                                std::cout << deg+1;
                                break;
                            }
                    }
                }
                q.pop();
            };
            if(!flag)
                std::cout <<-1;
        };

};

int main(){
    int n,m;
    std::cin >> n >> m;
    tomato toma(n,m);
    toma.set_map();
    toma.bfs();

    return 0;
}