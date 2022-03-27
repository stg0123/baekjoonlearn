#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class cal_fam{
private:
    vector<vector<int>> graph;
    int N,M;
    int START,END;
public:
    cal_fam(){
        std::cin >> N;
        std::cin >> START >> END;
        std::cin >> M;
        graph.resize(N+1);
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
    void dfs(){
        queue<pair<int,int>> q;
        q.push({START,0}); 
        vector<bool> visit(N+1,false);
        visit[START]=true;
        pair<int,int> cur;
        while(!q.empty()){
            cur =q.front();
            q.pop();
            if(cur.first==END){
                std::cout<< cur.second;
                return ;
            }
            for(int i : graph[cur.first]){
                if(!visit[i]){
                    visit[i]=true;
                    q.push({i,cur.second+1});
                }
            }
        }
        std::cout << -1 << '\n';
    }


};
int main(){
    cal_fam cf;
    cf.dfs();
    return 0;
}