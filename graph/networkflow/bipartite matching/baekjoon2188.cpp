#include <iostream>
#include <vector>
using namespace std;
class cow_matching{
private:
    vector<vector<int>> link;
    vector<bool> visit;
    vector<int> sol;
    int N,M;
public:
    cow_matching(){
        std::cin >> N >> M;
        link.resize(N+1);
        visit.resize(M+1);
        sol.resize(M+1,0);
        set_val();
    }
    void set_val(){
        int n,a;
        for(int i=1;i<=N;i++){
            std::cin >> n;
            for(int j=0;j<n;j++){
                std::cin >> a;
                link[i].push_back(a);
            }
        }
    }
    int dfs(int n){
        for(int i : link[n]){
            if(visit[i])
                continue;
            visit[i]=true;
            if(sol[i]==0||dfs(sol[i])){
                sol[i]=n;
                return 1;
            }
        }
        return 0;
    }
    void bi_matching(){
        int sol=0;
        for(int i=1;i<=N;i++){
            fill(visit.begin(),visit.end(),false);
            sol+=dfs(i);
        }
        std::cout << sol;
    }


};
int main(){
    cow_matching cm;
    cm.bi_matching();
    return 0;
}