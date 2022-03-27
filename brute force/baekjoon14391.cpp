#include <iostream>
#include <vector>
using namespace std;
class paper{
private:
    vector<vector<char>> map;
    vector<vector<bool>> visit;
    int N,M,MAX=0;
public:
    paper(){
        std::cin >> N >> M;
        map.resize(N,vector<char>(M));
        visit.resize(N,vector<bool>(M,false));
        set_val();
        
    }

    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                std::cin >> map[i][j];
    }
    
    void dfs(int x,int y,int val){
        if(y==M){
            dfs(x+1,0,val);
            return ;
        }
        else if(x==N){
            MAX=max(MAX,val);
            return ;
        }
        else if(visit[x][y]==true){
            dfs(x,y+1,val);
            return ;
        }
        string str = "";
        for(int cy = y;cy<M;cy++){
            if(visit[x][cy]==true)
                break;
            str+=map[x][cy];
            for(int j=y;j<=cy;j++)
                visit[x][j]=true;
            dfs(x,cy+1,val+stoi(str));
            for(int j=y;j<=cy;j++)
                visit[x][j]=false;

        }
        str = "";
        for(int cx = x ; cx<N;cx++){
            if(visit[cx][y]==true)
                break;
            str+=map[cx][y];
            for(int i=x;i<=cx;i++)
                visit[i][y]=true;
            dfs(x,y+1,val+stoi(str));
            for(int i=x;i<=cx;i++)
                visit[i][y]=false;
        }
        


    }
    void find_sol(){
        dfs(0,0,0);
        std::cout << MAX << "\n";
    }




};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    paper pp;
    pp.find_sol();

    return 0;
}