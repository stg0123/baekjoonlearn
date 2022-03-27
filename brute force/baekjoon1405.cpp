#include <iostream>
#include <vector>
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
class crazy{
private:
    vector<double> probablity;
    vector<vector<bool>> visit;
    int N;
public:
    crazy(){
        std::cin >> N;
        probablity.resize(4);
        visit.resize(N*2+1,vector<bool>(N*2+1,false));
        set_val();
    }
    void set_val(){
        for(int i=0;i<4;i++)
            std::cin >> probablity[i];
    }
    double dfs(int x,int y,int cur,double pb){
        if(cur == N)
            return pb;
        double sum=0;
        int nx,ny;
        for(int i=0;i<4;i++){
            nx=x+dx[i],ny=y+dy[i];
            if(!visit[nx][ny] && probablity[i]!=0){
                visit[nx][ny]=true;
                sum += dfs(nx,ny,cur+1,pb*probablity[i]/100);
                visit[nx][ny]=false;
            }
        }
        return sum;
    }
    void find_sol(){
        visit[N][N]=true;
        cout.precision(15);
        std::cout << dfs(N,N,0,1)<<'\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    crazy cy;
    cy.find_sol();

    return 0;
}