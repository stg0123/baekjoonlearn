#include <iostream>
#include <vector>
using namespace std;
class icecream{
private:
    vector<vector<int>> ban;
    vector<int> visit;
    vector<int> test;
    int N,M;
public:
    icecream(){
        std::cin >> N >> M;  
        ban.resize(N+1);
        visit.resize(N+1,0);
        test.resize(3);
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a >> b;
            if(a>b)
                swap(a,b);
            ban[a].push_back(b);
        }
    }
    int dfs(int cur,int depth){
        if(depth==3)
            return 1;
        
        int sol=0;
        for(int i=cur+1;i<=(N-2+depth);i++){
            if(!visit[i]){
                for(int b : ban[i])
                    visit[b]++;
                sol+=dfs(i,depth+1);
                for(int b : ban[i])
                    visit[b]--;
            }
        }
        return sol;
    }

    void find_sol(){
        std::cout << dfs(0,0)<<'\n';
    }


};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    icecream ic;
    ic.find_sol();

    return 0;
}