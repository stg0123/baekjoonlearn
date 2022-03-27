#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef struct node{
    int data;
    vector<node*> edge;
}node;
class dfs{
private:
    vector<node> map;
    vector<bool> visit;
    int N,M;
    int cal;
public :
    dfs(int n,int m):N(n),M(m){
        map.resize(n+1);
        visit.resize(n+1,false);
        for(int i=1;i<=n;i++)
            map[i].data=i;
        cal=0;
    };
    void set_connect(){
        int tmp1,tmp2;
        for(int i=0;i<M;i++){
            std::cin >> tmp1>> tmp2;

            map[tmp1].edge.push_back(&map[tmp2]);
            map[tmp2].edge.push_back(&map[tmp1]);
        }
    }
    void dfs_cal(int x){
        if(visit[x]==true)
            return ;
        stack<node*> st;
        st.push(&map[x]);
        visit[x]=true;
        int tmp;
        while(!st.empty()){
            tmp =st.top()->data;
            st.pop();
            for(int i=0;i<map[tmp].edge.size();i++)
                if(visit[map[tmp].edge[i]->data]==false){
                    st.push(map[tmp].edge[i]);
                    visit[map[tmp].edge[i]->data]=true;
                }
        }
        cal++;
    };

    void print_cal(){
        std::cout << cal << '\n';
    };

};
int main(){
    int n,m;
    std::cin >> n >> m;
    dfs df(n,m);
    df.set_connect();
    for(int i=1;i<=n;i++)
        df.dfs_cal(i);
    df.print_cal();

}