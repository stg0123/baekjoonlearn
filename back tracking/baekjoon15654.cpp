#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class NandM{
private:
    int N,M;
    vector<int> val;
    vector<bool> visit;
    vector<int> sol;
public:
    NandM(){
        std::cin >> N >> M;
        val.resize(N+1);
        visit.resize(N+1,false);
        sol.resize(M+1);
        set_val();
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> val[i];
        sort(val.begin()+1,val.end());
    }
    void dfs(int cur,int degree){
        sol[degree] =val[cur];
        if(degree==M){
            for(int i=1;i<=M;i++)
                std::cout << sol[i] << ' ';
            std::cout << '\n';
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
    NandM nm;
    nm.dfs(0,0);
    return 0;
}