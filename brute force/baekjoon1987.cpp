#include <iostream>
#include <vector>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
class alpha{
private:
    vector<string> map;
    int R,C;
    int sol;
public:
    alpha(){
        std::cin >> R >> C;
        map.resize(R);
        sol=0;
        set_val();
    }
    void set_val(){
        for(int i=0;i<R;i++)
            std::cin >> map[i];
    }
    void start_dfs(){
        DFS(0,0,1<<(map[0][0]-'A'),1);
        std::cout << sol<<'\n';
    }
    void DFS(int x,int y,int bit,int deepth){
        int tmp;
        sol=max(sol,deepth);
        for(int i=0;i<4;i++){
            if(x+dx[i]>=0&&x+dx[i]<R&&y+dy[i]>=0&&y+dy[i]<C){
                tmp =map[x+dx[i]][y+dy[i]]-'A';
                if(!(bit&(1<<tmp)))
                    DFS(x+dx[i],y+dy[i],bit|(1<<tmp),deepth+1);
            }
        }
    }

};
int main(){
    alpha ap;
    ap.start_dfs();
    return 0;
}