#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
struct _node{
    int capacity;
    int flow;
};
class city_nf_basic{
private:
    vector<vector<_node>> c_f;
    vector<vector<int>> connect;
    vector<int> prev;
    int N,P;
public:
    city_nf_basic(){
        std::cin >> N >> P;
        c_f.resize(N+1,vector<_node>(N+1));
        connect.resize(N+1);
        prev.resize(N+1);
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<P;i++){
            std::cin >> a >> b;
            connect[a].push_back(b);
            connect[b].push_back(a);
            c_f[a][b].capacity=1;
        }
    }
    void edmond_karp(int sorce,int sink){
        int cur,next;
        int result=0;
        while(1){
            fill(prev.begin(),prev.end(),-1);
            queue<int> q;
            q.push(sorce);
            while(!q.empty()){
                cur = q.front();
                q.pop();
                for(int i=0;i<connect[cur].size();i++){
                    next=connect[cur][i];
                    if(c_f[cur][next].capacity-c_f[cur][next].flow>0 && prev[next]==-1){
                        q.push(next);
                        prev[next]=cur;
                        if(next==sink)
                            break;
                    }
                }
            }
            if(prev[sink]==-1)
                break;
            int flow=INF;
            for(int i=sink;i!=sorce;i=prev[i])
                flow=min(flow,c_f[prev[i]][i].capacity-c_f[prev[i]][i].flow);
            for(int i=sink;i!=sorce;i=prev[i]){
                c_f[prev[i]][i].flow+=flow;
                c_f[i][prev[i]].flow-=flow;
            }
            result+=flow;
        }
        std::cout << result;

    }

};
int main(){
    city_nf_basic cb;
    cb.edmond_karp(1,2);
    return 0;
}