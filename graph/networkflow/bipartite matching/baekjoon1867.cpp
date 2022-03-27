#include <iostream>
#include <vector>
using namespace std;
struct _node{
    vector<int> link;
};
class rook{
private:
    vector<_node> map;
    vector<bool> visit;
    vector<int> sol;
    int N,K;
public:
    rook(){
        std::cin >> N >> K;
        map.resize(N+1);
        sol.resize(N+1);
        visit.resize(N+1);
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<K;i++){
            std::cin >> a >>b;
            map[a].link.push_back(b);
        }
    }
    int dfs(int n){
        for(int i : map[n].link){
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
        int result=0;
        for(int i=1;i<=N;i++){
            fill(visit.begin(),visit.end(),false);
            result+=dfs(i);
        }
        std::cout << result;
    }
};
int main(){
    rook r;
    r.bi_matching();

    return 0;
}