#include <iostream>
#include <vector>
using namespace std;
class backtracking{
private:
    vector<int> visit;
    vector<int> sol;
    int N;
public:
    backtracking(){
        std::cin >> N;
        sol.resize(N+1);
        visit.resize(N+1,false);   
    }
    void dfs(int cur,int degree){
        sol[degree]=cur;
        if(degree==N){
            for(int i=1;i<=N;i++)
                std::cout <<sol[i] <<' ';
            std::cout <<'\n';
            return ;
        }
        for(int i=1;i<=N;i++){
            if(!visit[i]){
                visit[i]=true;
                dfs(i,degree+1);
                visit[i]=false;   
            }
        }
    }
};
int main(){
    backtracking bt;
    bt.dfs(0,0);
    return 0;
}