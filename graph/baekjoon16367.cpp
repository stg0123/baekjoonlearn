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
class TV_show{
private:
    vector<_node> graph;
    vector<vector<int>> SCC;
    stack<int> st;
    int id,scc_id;
    int N,M;
public:
    TV_show(){
        std::cin >> N >> M;
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
        int a,b,c;
        char a_c,b_c,c_c;
        for(int i=0;i<M;i++){
            std::cin >>a >> a_c >> b >> b_c >> c >> c_c;
            if(a_c=='B')
                a=a+N;
            if(b_c=='B')
                b=b+N;
            if(c_c=='B')
                c=c+N;
            graph[OR(a)].edge.push_back(b);
            graph[OR(a)].edge.push_back(c);
            graph[OR(b)].edge.push_back(a);
            graph[OR(b)].edge.push_back(c);
            graph[OR(c)].edge.push_back(a);
            graph[OR(c)].edge.push_back(b);
        }
    }
    int TarjanDFS(int cur){
        st.push(cur);
        graph[cur].id=id++;
        int lowlink=graph[cur].id;
        int tmp;
        for(int i=0;i<graph[cur].edge.size();i++){
            tmp=graph[cur].edge[i];
            if(graph[tmp].scc_id!=-1)
                continue;
            if(graph[tmp].id==0)
                lowlink=min(lowlink,TarjanDFS(tmp));
            else
                lowlink=min(lowlink,graph[tmp].id);
        }
        if(lowlink == graph[cur].id){
            vector<int> scc;
            while(1){
                tmp= st.top();
                st.pop();
                graph[tmp].scc_id=scc_id;
                scc.push_back(tmp);
                if(tmp==cur)
                    break;
            }
            scc_id ++;
            SCC.push_back(scc);
        }
        return lowlink;
    }
    void print_SCC(){
        for(int i=0;i<scc_id;i++){
            for(int j=0;j<SCC[i].size();j++)
                std::cout <<SCC[i][j] << ' ';
            std::cout << '\n';
        }
    }
    void start_scc(){
        for(int i=1;i<=N*2;i++)
            if(graph[i].id==0)
                TarjanDFS(i);
        for(int i=1;i<=N;i++){
            if(graph[i].scc_id==graph[i+N].scc_id){
                std::cout << -1;
                return ;
            }
        }
        int tmp;
        for(int i=scc_id-1;i>=0;i--){
            for(int j=0;j<SCC[i].size();j++){
                tmp =SCC[i][j];
                if(tmp>N){
                    if(graph[tmp-N].result==-1)
                        graph[tmp-N].result=1;
                }
                else{
                    if(graph[tmp].result==-1)
                        graph[tmp].result=0;
                }
            }
        }
        for(int i=1;i<=N;i++){
            if(graph[i].result==1)
                std::cout << 'R';
            else if(graph[i].result==0)
                std::cout << 'B';
        }
        return ;
    }



};
int main(){
    TV_show tv;
    tv.start_scc();

    return 0;
}