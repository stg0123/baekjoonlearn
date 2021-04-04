#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
struct _node{
    int capacity;
    int flow;
};
int ctoi(char ch){
    return ch<='Z'? ch-'A' :ch-'a'+26;
};
class max_flow{
private:
    vector<vector<_node>> cf;
    vector<vector<int>> path;
    vector<int> prev;
    int N;
public:
    max_flow(){
        std::cin >> N;
        cf.resize(52,vector<_node>(52));
        path.resize(52);
        prev.resize(52);
        set_val();
    }
    void set_val(){
        char a,b;
        int ia,ib,cp;
        for(int i=0;i<N;i++){
            std::cin >>a >> b >> cp;
            ia=ctoi(a);
            ib=ctoi(b);
            path[ia].push_back(ib);
            path[ib].push_back(ia);
            cf[ia][ib].capacity+=cp;
            cf[ib][ia].capacity+=cp;
        }
    }
    void edmond_karp(int sorce,int sink){
        int cur,next;
        int result=0;
        while(1){
            fill(prev.begin(),prev.end(),-1);
            queue<int> q;
            q.push(sorce);
            while(!q.empty() && prev[sink]==-1){
                cur=q.front();
                q.pop();
                for(int i=0;i<path[cur].size();i++){
                    next=path[cur][i];
                    if(cf[cur][next].capacity-cf[cur][next].flow>0 && prev[next]==-1){
                        q.push(next);
                        prev[next]=cur;
                        if(next==sink)
                            break;
                    }
                }
            }
            if(prev[sink]==-1)
                break;
            int flow =INF;
            for(int i=sink;i!=sorce;i=prev[i])
                flow=min(flow,cf[prev[i]][i].capacity-cf[prev[i]][i].flow);
            for(int i=sink;i!=sorce;i=prev[i]){
                cf[prev[i]][i].flow+=flow;
                cf[i][prev[i]].flow-=flow;
            }
            result+=flow;
        }
        std::cout << result;
    }

};
int main(){
    max_flow mf;
    mf.edmond_karp(ctoi('A'),ctoi('Z'));
    return 0;   
}