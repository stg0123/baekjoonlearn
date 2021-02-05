#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct _node{
    int id;
    int scc_id;
    int result;
    vector<int> edge;
};
class sat_2{
private:
    vector<_node> graph;
    stack<int> st;
    vector<vector<int>> SCC;
    int id,scc_id;
    int N,M;
public:
    sat_2(){
        std::cin >> N>>M;
        graph.resize(N*2+1,{0,-1,-1,});
        id=1;
        scc_id=0;
        set_connect();
    }
    int OR(int a){
        if(a>N)
            return a-N;
        else
            return a+N;
    }
    void set_connect(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a>> b;
            if(a<0)
                a=abs(a)+N;
            if(b<0)
                b=abs(b)+N;
            graph[OR(a)].edge.push_back(b);
            graph[OR(b)].edge.push_back(a);
        }
    }
    int TarjanDFS(int cur){
        st.push(cur);
        graph[cur].id=id++;
        int lowlink=graph[cur].id;
        int tmp;
        for(int i=0;i<graph[cur].edge.size();i++){
            tmp =graph[cur].edge[i];
            if(graph[tmp].scc_id!=-1)
                continue;
            if(graph[tmp].id==0)
                lowlink=min(lowlink,TarjanDFS(tmp));
            else
                lowlink=min(lowlink,graph[tmp].id);
        }
        if(lowlink==graph[cur].id){
            vector<int> scc;
            while(1){
                tmp=st.top();
                st.pop();
                scc.push_back(tmp);
                graph[tmp].scc_id=scc_id;
                if(tmp==cur)
                    break;
            }
            scc_id++;
            SCC.push_back(scc);
        }
        return lowlink;
    }
    void find_2sat(){
        for(int i=1;i<=N*2;i++)
            if(graph[i].id==0)
                TarjanDFS(i);
        for(int i=1;i<=N;i++)
            if(graph[i].scc_id==graph[i+N].scc_id){
                std::cout << 0 << '\n';
                return ;
            }
        std::cout << 1 << '\n';
        int tmp;
        for(int i=scc_id-1;i>=0;i--){
            for(int j=0;j<SCC[i].size();j++){
                tmp=SCC[i][j];
                if(tmp>N){
                    if(graph[tmp-N].result==-1)
                        graph[tmp-N].result=1;
                }
                else
                    if(graph[tmp].result==-1)
                        graph[tmp].result=0;
            }
        }
        for(int i=1;i<=N;i++)
            std::cout << graph[i].result << ' ';
        
        return ;
    }

};
int main(){
    sat_2 sat;
    sat.find_2sat();


    return 0;
}