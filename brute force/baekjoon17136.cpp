#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int INF=1000000000;
class colorpaper{
private:
    vector<vector<int>> map;
    vector<int> avaliable;
    int N=10,sol=INF;
public:
    colorpaper(){
        map.resize(N,vector<int>(N));
        avaliable.resize(5,5);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                std::cin >> map[i][j];
            }
        }
    }
    bool check(int x,int y,int d){
        for(int i=x;i<x+d;i++){
            for(int j=y;j<y+d;j++){
                if(map[i][j]==0){
                    return false;
                }
            }
        }
        for(int i=x;i<x+d;i++){
            for(int j=y;j<y+d;j++){
                map[i][j]=0;
            }
        }
        return true;

    }
    void checkout(int x,int y,int d){
        for(int i=x;i<x+d;i++)
            for(int j=y;j<y+d;j++)
                map[i][j]=1;
    }
    void dfs(int x,int y,int result){
        if(y==N){
            dfs(x+1,0,result);
            return ;
        }
        if(x==N){
            sol=min(sol,result);
            return ;
        }
        if(map[x][y]==0){
            dfs(x,y+1,result);
            return ;
        }
        for(int i=0;i<5;i++){
            if(avaliable[i] && x+i<N && y+i<N){
                if(check(x,y,i+1)){
                    avaliable[i]--;
                    dfs(x,y+i+1,result+1);
                    avaliable[i]++;
                    checkout(x,y,i+1);
                }
            }
        }
    }
    void find_sol(){
        dfs(0,0,0);
        if(sol==INF)
            std::cout << -1 << '\n';
        else
            std::cout << sol << '\n';
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    colorpaper cp;
    cp.find_sol();
    return 0;
}