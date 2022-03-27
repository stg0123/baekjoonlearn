#include <iostream>
#include <vector>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
class max_water{
private:
    vector<vector<int>> map;
    int N,max_num;
    vector<vector<bool>> visit;
public:
    max_water(){
        std::cin >> N;
        map.resize(N,vector<int>(N,0));
        max_num=0;
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                std::cin >> map[i][j];
                max_num=max(max_num,map[i][j]);
            }
        }
    }
    void DFS(int x,int y,int val){
        for(int i=0;i<4;i++){
            if(x+dx[i]>=0&&x+dx[i]<N&&y+dy[i]>=0&&y+dy[i]<N){
                if(!visit[x+dx[i]][y+dy[i]]&&map[x+dx[i]][y+dy[i]]>val){
                    visit[x+dx[i]][y+dy[i]]=true;
                    DFS(x+dx[i],y+dy[i],val);
                }
            }
        }
    }
    void find_max(){
        int sol=1,tmp;
        for(int val=1;val<=max_num;val++){
            tmp=0;
            visit.clear();
            visit.resize(N,vector<bool>(N,false));
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(!visit[i][j]&&map[i][j]>val){
                        visit[i][j]=true;
                        DFS(i,j,val);
                        tmp++;
                    }
                }
            }
            sol=max(sol,tmp);
        }
        std::cout << sol ;
    }


};
int main(){
    max_water mw;
    mw.find_max();
    return 0;
}