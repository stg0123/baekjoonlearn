#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[5]={1,0,-1,0,0};
int dy[5]={0,1,0,-1,0};
int INF = 1000000000;
class flower{
private:
    vector<vector<int>> map;
    int N;
public:
    flower(){
        std::cin >> N;
        map.resize(N,vector<int>(N));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                std::cin >> map[i][j];
    }
    int flower_val(vector<bool>& check){
        vector<vector<bool>> visit(N,vector<bool>(N,false));
        int x,y,nx,ny;
        int sol=0;
        for(int i=0;i<N*N;i++){
            x = i/N;
            y = i%N;
            if(check[i]){
                for(int j=0;j<5;j++){
                    nx = x+dx[j],ny = y+dy[j];
                    if(nx<0 || nx >=N || ny<0 || ny >=N)
                        return INF;
                    if(!visit[nx][ny]){
                        visit[nx][ny]=true;
                        sol+=map[nx][ny];
                    }
                    else
                        return INF;
                }
            }
        }
        return sol;
    }

    void find_sol(){
        vector<bool> check(N*N,false);
        int sol=INF;
        for(int i=0;i<3;i++)
            check[i]=true;
        do{
            sol=min(sol,flower_val(check));
        }while(prev_permutation(check.begin(),check.end()));
        std::cout << sol << '\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    flower fl;
    fl.find_sol();
    return 0;
}
