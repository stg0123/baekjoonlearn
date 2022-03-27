#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct _node{
    int pre;
    vector<int> edge;
};
struct compare{
    bool operator()(int& a,int& b){
        return a>b;
    }
};
class problem_sol{
private:
    vector<_node> map;
    int N,M;
public:
    problem_sol(){
        std::cin >> N >> M;
        map.resize(N+1,{0,});
        set_connect();
    }
    void set_connect(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a>> b;
            map[a].edge.push_back(b);
            map[b].pre++;
        }
    }
    void prior_dfs(){
        priority_queue<int,vector<int>,compare> pq;
        vector<int> sol;
        for(int i=1;i<=N;i++){
            if(map[i].pre==0)
                pq.push(i);
        }
        int cur,tmp;
        while(!pq.empty()){
            cur=pq.top();
            pq.pop();
            sol.push_back(cur);
            for(int i=0;i<map[cur].edge.size();i++){
                tmp=map[cur].edge[i];
                if(--map[tmp].pre==0)
                    pq.push(tmp);
            }
        }
        for(int i=0;i<sol.size();i++)
            std::cout << sol[i]<<' ';
        std::cout << '\n';
    }

};
int main(){
    problem_sol ps;
    ps.prior_dfs();
    return 0;
}