#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct _cpt{
    int cnt=-1;
    vector<int> edge;
};
class hacking{
private:
    vector<_cpt> computer;
    int N,M;
    int MAX=0;
public:
    hacking(){
        std::cin >> N >> M;
        computer.resize(N+1);
        set_connect();
    }
    void set_connect(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a >> b;
            computer[b].edge.push_back(a);
        }
    }
    void dfs(int a){
        vector<bool> visit(N+1,false);
        stack<int> st;
        st.push(a);
        visit[a]=true;
        int cur,cnt=0;
        while(!st.empty()){
            cur = st.top();
            st.pop();
            // if(computer[cur].cnt!=-1){
            //     cnt+=computer[cur].cnt;
            //     continue;
            // }
            for(int i : computer[cur].edge){
                if(!visit[i]){
                    visit[i]=true;
                    st.push(i);
                    cnt++;
                }
            }
        }
        computer[a].cnt =cnt;
        MAX = max(computer[a].cnt,MAX);
    }
    void find_sol(){
        for(int i=1;i<=N;i++)
            dfs(i);
        for(int i=1;i<=N;i++)
            if(computer[i].cnt==MAX)
                std::cout << i << ' ';
        std::cout << '\n';
    }
    
};
int main(){
    hacking hk;
    hk.find_sol();

    return 0;
}