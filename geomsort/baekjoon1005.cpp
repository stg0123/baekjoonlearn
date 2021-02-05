#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct _node{
    int pre;
    int weight;
    vector<int> edge;
};
class ACM_craft{
private:
    vector<_node> map;
    vector<int> dp;
    int N,M;
    int sol_num;
public:
    ACM_craft(){
        std::cin >> N>> M;
        map.resize(N+1,{0,0,});
        dp.resize(N+1,0);
        set_connect();
    }
    void set_connect(){
        for(int i=1;i<=N;i++){
            std::cin >> map[i].weight;
        }
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a >> b;
            map[a].edge.push_back(b);
            map[b].pre++;
        }
        std::cin >>sol_num;
    }
    void dfs_dp(){
        queue<int> q;
        for(int i=1;i<=N;i++){
            if(map[i].pre==0)
                q.push(i);
        }
        int cur,tmp;
        while(!q.empty()){
            cur =q.front();
            q.pop();
            if(cur==sol_num){
                std::cout << dp[cur]+map[cur].weight<<'\n';
                return ;
            }
            for(int i=0;i<map[cur].edge.size();i++){
                tmp=map[cur].edge[i];
                if(dp[tmp]<map[cur].weight+dp[cur])
                    dp[tmp]=map[cur].weight+dp[cur];
                if(--map[tmp].pre==0)
                    q.push(tmp);
            }
        }
    }


};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        ACM_craft AC;
        AC.dfs_dp();
    }
    return 0;
}