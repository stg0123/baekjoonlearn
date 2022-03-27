#include <iostream>
#include <vector>
using namespace std;
class ladder{
private:
    vector<vector<int>> map;
    int N,M,H;
public:
    ladder(){
        std::cin >> N >> M >> H;
        map.resize(H,vector<int>(N,0));
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a >> b;
            a--,b--;
            map[a][b]=1;
            map[a][b+1]=-1;
        }
        // for(int i=0;i<H;i++){
        //     for(int j=0;j<N;j++){
        //         if(map[i][j]==-1)
        //             std::cout << map[i][j];
        //         else
        //             std::cout <<' '<< map[i][j];            
        //     }
        //     std::cout << '\n';
        // }
    }
    bool check(int a){
        int cur=a;
        for(int i=0;i<H;i++)
            cur+=map[i][cur];
        return a==cur;
    }
    bool dfs(int depth,int m,int x,int y){
        if(depth==m){
            for(int i=0;i<N-1;i++){
                if(!check(i))
                    return false;
            }
            return true;
        }
        bool flag=false;
        for(int j=y;j<N-1;j++){
            if(!map[x][j] && !map[x][j+1]){
                map[x][j]=1,map[x][j+1]=-1;
                flag|=dfs(depth+1,m,x,j);
                map[x][j]=0,map[x][j+1]=0;
            }
        }
        for(int i=x+1;i<H;i++){
            for(int j=0;j<N-1;j++){
                if(!map[i][j] && !map[i][j+1]){
                    map[i][j]=1,map[i][j+1]=-1;
                    flag|=dfs(depth+1,m,i,j);
                    map[i][j]=0,map[i][j+1]=0;
                }
            }
        }
        return flag;
    }
    void find_sol(){
        for(int i=0;i<4;i++){
            if(dfs(0,i,0,0)){
                std::cout << i<<'\n';
                return ;
            }
        }
        std::cout << -1 <<'\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    ladder ld;
    ld.find_sol();   
    return 0;
}