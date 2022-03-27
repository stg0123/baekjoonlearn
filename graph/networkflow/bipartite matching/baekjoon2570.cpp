#include <iostream>
#include <vector>
using namespace std;
class vishop{
private:
    vector<vector<int>> link;
    vector<bool> visit;
    vector<int> sol;
    int N;
    int dia1=0,dia2=0;
public:
    vishop(){
        std::cin >> N;
        set_val();
        sol.resize(dia2+1);
        visit.resize(dia2+1);
    }
    void set_val(){
        vector<vector<int>> diagonal1(N,vector<int>(N,0));
        vector<vector<int>> diagonal2(N,vector<int>(N,0));
        int n,x,y;
        std::cin >> n;
        for(int i=0;i<n;i++){
            std::cin >>x >> y;
            diagonal1[x-1][y-1]=-1;
            diagonal2[x-1][y-1]=-1;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(diagonal1[i][j]==-1)
                    continue;
                if(i-1<0 || j-1<0)
                    diagonal1[i][j]=++dia1;
                else if(diagonal1[i-1][j-1]==-1)
                    diagonal1[i][j]=++dia1;
                if(i-1<0 || j+1>=N)
                    diagonal2[i][j]=++dia2;
                else if(diagonal2[i-1][j+1]==-1)
                    diagonal2[i][j]=++dia2;
            }
        }
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<N;j++)
        //         std::cout << diagonal1[i][j]<<' ';
        //     std::cout << '\n';
        // }
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<N;j++)
        //         std::cout << diagonal2[i][j]<<' ';
        //     std::cout << '\n';
        // }
        link.resize(dia1+1);
        int a,b;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(diagonal1[i][j]==-1)
                    continue;
                x=i,y=j;
                while(!diagonal1[x][y]){
                    x--,y--;
                }
                a=diagonal1[x][y];
                x=i,y=j;
                while(!diagonal2[x][y]){
                    x--;y++;
                }
                b=diagonal2[x][y];
                link[a].push_back(b);
            }
        }

    }
    int dfs(int n){
        for(int i : link[n]){
            if(visit[i])
                continue;
            visit[i]=true;
            if(sol[i]==0 || dfs(sol[i])){
                sol[i]=n;
                return 1;
            }
        }
        return 0;
    }   
    void bi_matching(){
        int sol=0;
        for(int i=1;i<=dia1;i++){
            fill(visit.begin(),visit.end(),false);
            sol+=dfs(i);
        }
        std::cout << sol;
        
    }
    
};
int main(){
    vishop vs;
    vs.bi_matching();
    return 0;
}