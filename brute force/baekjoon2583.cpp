#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
class area_cal{
private:
    vector<vector<bool>> visit;
    int M,N;
    vector<int> val;
public:
    area_cal(){
        std::cin >> M >> N;
        visit.resize(M,vector<bool>(N,false));
        val.resize(M*N,1);
        set_val();
    }
    void set_val(){
        int n,x1,y1,x2,y2;
        std::cin >> n;
        for(int i=0;i<n;i++){
            std::cin >> x1 >>y1 >>x2 >>y2;
            for(int x=x1;x<x2;x++){
                for(int y=y1;y<y2;y++){
                    visit[y][x]=true;
                }
            }
        }
    }
    void setart_dfs(){
        int sol=0;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(!visit[i][j]){
                    visit[i][j]=true;
                    DFS(i,j,sol);
                    sol++;
                }
            }
        }
        std::cout << sol<<'\n';
        sort(val.begin(),val.begin()+sol);
        for(int i=0;i<sol;i++){
            std::cout << val[i] << ' ';
        }
    }

    void DFS(int x,int y,int index){
        for(int i=0;i<4;i++){
            if(x+dx[i]>=0&&x+dx[i]<M&&y+dy[i]>=0&&y+dy[i]<N){
                if(!visit[x+dx[i]][y+dy[i]]){
                    visit[x+dx[i]][y+dy[i]]=true;
                    val[index]++;
                    DFS(x+dx[i],y+dy[i],index);
                }
            }
        }
    }


};
int main(){
    area_cal ac;
    ac.setart_dfs();
    return 0;
}