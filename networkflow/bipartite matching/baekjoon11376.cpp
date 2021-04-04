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
        std::cin >> N>> M;
        sol.resize(M+1,0);
        map.resize(N*2+1);
        visit.resize(M+1,false);
        set_val();
    }
    void set_val(){
        int n,a;
        for(int i=1;i<=N;i++){
            std::cin >> n;
            for(int j=0;j<n;j++){
                std::cin >> a;
                map[i*2-1].link.push_back(a);
                map[i*2].link.push_back(a);
            }
        }
    }
    bool dfs(int n){
        for(int i : map[n].link){
            if(visit[i])
                continue;
            visit[i]=true;
            if(sol[i]==0 || dfs(sol[i])){
                sol[i]=n;
                return true;
            }
        }
        return false;
    }
    void find_sol(){
        int sol=0;
        for(int i=1;i<=2*N;i++){
            fill(visit.begin(),visit.end(),false);            
            if(dfs(i))
                sol++;
        }
        std::cout << sol;
    }


};
int main(){
    bi_matching bm;
    bm.find_sol();

    return 0;
}