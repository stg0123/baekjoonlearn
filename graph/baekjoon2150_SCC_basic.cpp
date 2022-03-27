#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct _node{
    int id;
    bool finished;
    vector<int> edge;
};
class SCC_Tarjan{
private:
    vector<_node> graph;
    stack<int> st;
    vector<vector<int>> SCC_sol;
    int id;
    int N,M;
public:
    SCC_Tarjan(){
        std::cin >>N>>M;
        id=1;
        graph.resize(N+1,{0,false,});
        set_connect();
    }
    void set_connect(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >>  a>>b;
            graph[a].edge.push_back(b);
        }
    }
    int tarjanDFS(int cur){
        st.push(cur);
        graph[cur].id=id++; 
        int lowlink = graph[cur].id;
        int tmp;
        for(int i=0;i<graph[cur].edge.size();i++){
            tmp =graph[cur].edge[i];
            if(graph[tmp].finished)
                continue;
            if(graph[tmp].id==0)
                lowlink = min(lowlink,tarjanDFS(tmp));
            else
                lowlink = min(lowlink,graph[tmp].id);
        }
        if(lowlink==graph[cur].id){
            vector<int> scc;

            while(1){
                tmp= st.top();
                st.pop();
                scc.push_back(tmp);
                graph[tmp].finished=true;
                if(tmp==cur)
                    break;
            }
            sort(scc.begin(),scc.end());
            SCC_sol.push_back(scc);
        }
        return lowlink;
    }

    void start_tarjan(){
        for(int i=1;i<=N;i++){
            if(graph[i].id==0)
                tarjanDFS(i);
        }
        sort(SCC_sol.begin(),SCC_sol.end());

        std::cout << SCC_sol.size() <<'\n';
        for(int i=0;i<SCC_sol.size();i++){
            for(int j=0;j<SCC_sol[i].size();j++)
                std::cout << SCC_sol[i][j] << ' ';
            std::cout << -1 << '\n';
        }

    }
};
struct node_{
    vector<int> edge;
};
class SCC_cosaraju{
private:
    vector<node_> graph,R_graph;
    vector<vector<int>> SCC_sol;
    vector<int> scc;
    stack<int> st;
    vector<bool> visited;
    int N,M;
public:
    SCC_cosaraju(){
        std::cin >> N>>M;
        graph.resize(N+1);
        R_graph.resize(N+1);
        visited.resize(N+1,false);
        set_connect();
    }
    void set_connect(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a >> b;
            graph[a].edge.push_back(b);
            R_graph[b].edge.push_back(a);
        }
    }
    void DFS(int cur){
        visited[cur]=true;
        int tmp;
        for(int i=0;i<graph[cur].edge.size();i++){
            tmp = graph[cur].edge[i];
            if(!visited[tmp])
                DFS(tmp);
        }
        st.push(cur);
    }
    void RDFS(int cur){
        visited[cur]=true;
        scc.push_back(cur);
        int tmp;
        for(int i=0;i<R_graph[cur].edge.size();i++){
            tmp = R_graph[cur].edge[i];
            if(!visited[tmp])
                RDFS(tmp);
        }
    }
    void start_cosaraju(){

        for(int i=1;i<=N;i++)
            if(!visited[i])
                DFS(i);
        
        visited.clear();
        visited.resize(N+1,false);
        int cur;
        while(!st.empty()){
            cur=st.top();
            st.pop();
            
            if(visited[cur]) continue;

            RDFS(cur);
            sort(scc.begin(),scc.end());
            SCC_sol.push_back(scc);
            scc.clear();
        }
    
        sort(SCC_sol.begin(),SCC_sol.end());
        std::cout << SCC_sol.size() << '\n';
        for(int i=0;i<SCC_sol.size();i++){
            for(int j=0;j<SCC_sol[i].size();j++)
                std::cout << SCC_sol[i][j] << ' ';
            std::cout << -1 << '\n';
        }

    }
};



int main(){
    SCC_cosaraju sccc;
    sccc.start_cosaraju();
    return 0;
}