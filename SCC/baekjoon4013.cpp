#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct _node{
    int id;
    int scc_id;
    int weight;
    vector<int> edge;
};
struct scc{
    int sum;
    vector<int> scc_edge;
};
class ATM{
private:
    vector<_node> graph;
    vector<scc> SCC;
    vector<int> dp;
    stack<int> st;
    int id,scc_id;
    int N,M;
public:
    ATM(){
        std::cin >> N >> M;
        graph.resize(N+1,{0,-1,});
        id=1;
        scc_id=0;
        set_node();
        set_SCC();
    }
    void print_SCC(){
        for(int i=0;i<scc_id;i++){
            std::cout << SCC[i].sum << ' ';
            // for(int j=0;j<SCC[i].scc_edge.size();j++){
            //     std::cout << SCC[i].scc_edge[j] << ' ';
            // }
        }
        std::cout << '\n';
    }
    void set_node(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a>>b;
            graph[a].edge.push_back(b);
        }
        for(int i=1;i<=N;i++){
            std::cin >> graph[i].weight;
        }
    }
    int tarjanDFS(int cur){
        st.push(cur);
        graph[cur].id=id++;
        int lowlink =graph[cur].id;
        int tmp;
        for(int i=0;i<graph[cur].edge.size();i++){
            tmp=graph[cur].edge[i];
            if(graph[tmp].scc_id!=-1)
                continue;
            if(graph[tmp].id==0)
                lowlink=min(lowlink,tarjanDFS(tmp));
            else
                lowlink=min(lowlink,graph[tmp].id);
        }
        if(lowlink==graph[cur].id){
            int sum=0;
            while(1){
                tmp=st.top();
                st.pop();
                sum+=graph[tmp].weight;
                graph[tmp].scc_id=scc_id;
                if(tmp==cur)
                    break;
            }
            SCC.push_back({sum,});
            scc_id++;
        }
        return lowlink;
    }
    void set_SCC(){
        for(int i=1;i<=N;i++)
            if(graph[i].id==0)
                tarjanDFS(i);
        int tmp;
        for(int i=1;i<=N;i++){
            for(int j=0;j<graph[i].edge.size();j++){
                tmp=graph[i].edge[j];
                if(graph[i].scc_id!=graph[tmp].scc_id)
                    SCC[graph[i].scc_id].scc_edge.push_back(graph[tmp].scc_id);
            }                
        }
    }
    void find_max_sum(){
        int start,end_num,end,tmp,sol=0;
        std::cin >> start >>end_num;
        start=graph[start].scc_id;
        dp.resize(scc_id,0);
        set_dp(start);
        for(int i=0;i<end_num;i++){
            std::cin >> end;
            sol=max(sol,dp[graph[end].scc_id]);
        }
        std::cout << sol << '\n';
    }


    void set_dp(int start){
        dp[start]=SCC[start].sum;
        int tmp;
        for(int i=start;i>=0;i--){
            for(int j=0;j<SCC[i].scc_edge.size();j++){
                tmp=SCC[i].scc_edge[j];
                dp[tmp]=max(dp[tmp],dp[i]+SCC[tmp].sum);
            }
        }
    }

};
int main(){
    ATM atm;
    atm.find_max_sum();

    return 0;
}