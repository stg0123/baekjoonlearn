#include <iostream>
#include <vector>
using namespace std;
struct _node{
    vector<int> link;
};
class bi_matching{
private:
    vector<_node> map;
    vector<bool> visit;
    vector<int> sol;
    int N,M;
public:
    bi_matching(){
        std::cin >> N>>M;
        map.resize(N+1);
        sol.resize(M+1,0);
        set_val();
    }
    void set_val(){
        int n,a;
        for(int i=1;i<=N;i++){
            std::cin >> n;
            for(int j=0;j<n;j++){
                std::cin >> a;
                map[i].link.push_back(a);
            }
        }
    }
    int dfs(int n){
        for(int i : map[n].link ){
            if(visit[i])
                continue;
            visit[i]=true;
            if(sol[i]==0 || dfs(sol[i])){
                sol[i] = n;
                return 1;
            }
        }
        return 0;
    }
    void find_sol(){
        int sol=0;
        for(int i=1;i<=N;i++){
            visit.clear();
            visit.resize(N+1,false);
            sol+=dfs(i);
        }
        std::cout << sol;
    }

};
int main(){
    bi_matching bm;
    bm.find_sol();

    return 0;
}