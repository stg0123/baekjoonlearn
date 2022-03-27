#include <iostream>// 3:52∫– Ω√¿€
#include <vector>
#include <queue>
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
using namespace std;
typedef struct node{
    int x,y;
    int degree;
    bool flag;
}node;
class buck{
    private:
        vector<vector<char>> map;
        int N,M,min;
    public:
        buck(int n,int m):N(n),M(m){
            map.resize(n);
            for(int i=0;i<n;i++)
                map[i].resize(m,'0');
            min=n*m;
        };
        void set_map(){
            for(int i=0;i<N;i++)
                for(int j=0;j<M;j++)
                    cin >> map[i][j];
        };
        void print_map(){
            std::cout<< '\n';
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++)
                    cout << map[i][j];
            std::cout <<'\n';
            }
        };

        void bfs(){
            queue<node> q;
            node tmp;
            tmp.x=0;
            tmp.y=0;
            tmp.flag=false;
            tmp.degree=1;
            q.push(tmp);
            map[0][0]='2';
            int x,y,deg;
            bool flag,f=false;
            while(!q.empty()){
                x=q.front().x;
                y=q.front().y;
                flag=q.front().flag;
                deg=q.front().degree;
                if(x==N-1&&y==M-1){
                    if(deg<min)
                        min=deg;
                    f=true;
                    q.pop();
                    continue;           
                }
                //std::cout << " x,y = "<< x <<','<< y << " flag =" <<flag <<" deg = "<< deg << '\n'; 
                for(int i=0;i<4;i++){
                    if(x+dx[i]>=0&&x+dx[i]<N&&y+dy[i]>=0&&y+dy[i]<M){
                        
                        if(map[x+dx[i]][y+dy[i]]=='0'){
                            
                            tmp.x=x+dx[i];
                            tmp.y=y+dy[i];
                            tmp.flag=flag;
                            tmp.degree=deg+1;
                            q.push(tmp);
                            if(flag==true)
                                map[x+dx[i]][y+dy[i]]='2';
                            else 
                                map[x+dx[i]][y+dy[i]]='3';
                            
                        }
                        if(map[x+dx[i]][y+dy[i]]=='1'&&!flag){
                            tmp.x=x+dx[i];
                            tmp.y=y+dy[i];
                            tmp.flag=true;
                            tmp.degree=deg+1;
                            q.push(tmp);
                        
                        }
                        if(map[x+dx[i]][y+dy[i]]=='2'&&!flag){
                            tmp.x=x+dx[i];
                            tmp.y=y+dy[i];
                            tmp.flag=flag;
                            tmp.degree=deg+1;
                            q.push(tmp);
                            map[x+dx[i]][y+dy[i]]='3';
                        }
                    }
                }
                q.pop();
            }
            if(f)
                std::cout <<min;
            else
                std::cout <<-1; 
        }

};
int main(){
    int n,m;
    cin >> n >> m;
    buck bu(n,m);
    bu.set_map();
    bu.bfs();
    return 0;
}