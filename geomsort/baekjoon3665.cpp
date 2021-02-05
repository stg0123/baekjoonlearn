#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class next_rank{
private:
    vector<int> pre;
    vector<vector<bool>> edge;
    int N;
public:
    next_rank(){
        std::cin >> N;
        pre.resize(N+1,0);
        edge.resize(N+1,vector<bool>(N+1,false));
        set_connect();
        //print_edge_pre();
    }
    void set_connect(){
        vector<int> pre_rank;
        int tmp,a,b;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            pre_rank.push_back(tmp);
        }
        for(int i=0;i<N-1;i++){
            a=pre_rank[i];
            for(int j=i+1;j<N;j++){
                b=pre_rank[j];
                edge[a][b]=true;
                pre[b]++;
            }
        }
        int M;
        std::cin >> M;
        for(int i=0;i<M;i++){
            std::cin >> a>>b;
            if(edge[a][b]){
                edge[a][b]=false;
                edge[b][a]=true;
                pre[b]--;
                pre[a]++;
            }
            else{
                edge[b][a]=false;
                edge[a][b]=true;
                pre[a]--;
                pre[b]++;
            }
        }

    }
    void print_edge_pre(){
        std::cout << '\n';
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++)
                std::cout << edge[i][j] << ' ';
            std::cout << '\n';
        }
        std::cout <<'\n';
        for(int i=1;i<=N;i++)
            std::cout << pre[i]<<' ';
        std::cout << '\n';
    }

    void dfs(){
        queue<int> q;
        vector<int> sol;
        for(int i=1;i<=N;i++)
            if(pre[i]==0)
                q.push(i);
        int cur;
        while(!q.empty()){
            if(q.size()>1){
                std::cout << "?\n";
                return ;
            }
            cur=q.front();
            q.pop();
            sol.push_back(cur);
            for(int i=1;i<=N;i++){
                if(edge[cur][i]==true)
                    if(--pre[i]==0)
                        q.push(i);
            }
        }
        if(sol.size()!=N)
            std::cout<< "IMPOSSIBLE\n";
        else
        {
            for(int i=0;i<sol.size();i++)
                std::cout << sol[i]<<' ';
            std::cout << '\n';
        }

    }

};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        next_rank nr;
        nr.dfs();
    }

    return 0;
}