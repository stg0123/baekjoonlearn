#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct node{
    vector<pair<int,int>> edge_dis;
};
class max_distance{
private:
    vector<node> tree;
    int N;
    int max_dis,max_idx;
public:
    max_distance(){
        std::cin >> N;
        tree.resize(N+1);  
        max_dis=-1;
        set_connect();
    }
    void set_connect(){
        int a,b,idx;
        for(int i=0;i<N;i++){
            std::cin >> idx;
            while(1){
                std::cin >> a;
                if(a==-1)
                    break;
                std::cin >> b;
                tree[idx].edge_dis.push_back({a,b});
            }
        }
        
    }
    void bfs(int START){
        stack<pair<int,int>> st;
        vector<bool> visit(N+1,false);
        st.push({START,0});
        visit[START]=true;
        int cur,c_dis;
        pair<int,int> tmp;
        while(!st.empty()){
            cur = st.top().first;
            c_dis = st.top().second;
            st.pop();
            if(c_dis>max_dis){
                max_dis =c_dis;
                max_idx =cur;
            }
            for(int i=0;i<tree[cur].edge_dis.size();i++){
                tmp= tree[cur].edge_dis[i];
                if(visit[tmp.first]==false){
                    visit[tmp.first]=true;
                    st.push({tmp.first,c_dis+tmp.second});
                }
            }
        }
    }

    void start(){
        bfs(1);
        bfs(max_idx);

        std::cout << max_dis << '\n';
    }
    

};
int main(){
    max_distance md;
    md.start();

    return 0;
}