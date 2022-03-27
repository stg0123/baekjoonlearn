#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct node{
    int data;
    vector<int> edge;
};
class binary_graph{
private:
    vector<node> map;
    int N,M;
public:
    binary_graph(int n,int m):N(n),M(m){
        node tmp;
        tmp.data=0;
        map.resize(n+1,tmp);
    };
    void set_val(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a >> b;
            map[a].edge.push_back(b);
            map[b].edge.push_back(a);
        }
    }
    void sol(){
        for(int i=1;i<=N;i++){
            if(map[i].data==0)
                if(!dfs(i)){
                    std::cout <<"NO\n";
                    return ;
                }
        }
        std::cout <<"YES\n";
    }

    bool dfs(int n){
        map[n].data=1;
        stack<int> st;
        st.push(n);
        int cur,tmp;
        while(!st.empty()){
            cur = st.top();
            st.pop();
            for(int i=0;i<map[cur].edge.size();i++){
                tmp=map[cur].edge[i];
                if(map[tmp].data==map[cur].data){
                    return false;
                }
                else if(map[tmp].data==0){
                    map[tmp].data =-map[cur].data;
                    st.push(tmp);
                }
            }
        }
        return true;
    }

};
int main(){
    int n,a,b;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> a>>b;
        binary_graph bi(a,b);
        bi.set_val();
        bi.sol();
    }
    return 0;
}