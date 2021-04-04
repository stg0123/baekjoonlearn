#include <iostream>
#include <vector>
using namespace std;
class lotto{
private:
    int N;
    vector<int> sol;
    vector<int> val;
    vector<bool> visit;
public:
    lotto(int n):N(n){
        sol.resize(7);
        val.resize(N+1);
        visit.resize(N+1,false);
        set_val();
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> val[i];
    }
    void dfs(int cur,int degree){
        sol[degree]=val[cur];
        if(degree==6){
            for(int i=1;i<=6;i++)
                std::cout << sol[i]<<' ';   
            std::cout << '\n';
            return ;
        }
        for(int i=cur+1;i<=N;i++){
            if(!visit[i]){
                visit[i]=true;
                dfs(i,degree+1);
                visit[i]=false;
            }
        }
        return ;
    }

};
int main(){
    while(1){
        int n;
        std::cin >> n;
        if(n==0)
            return 0;
        lotto l(n);
        l.dfs(0,0);
        std::cout << '\n';
    }
    return 0;
}