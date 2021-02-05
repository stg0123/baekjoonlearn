#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct _node{
    int parent;
    int depth;
    vector<int> edge;
};
class LCA_basic{
private:
    vector<_node> tree;
    vector<vector<int>> dp;
    int N,MAX_depth,MAX_pow;
public:
    LCA_basic(){
        std::cin >> N;
        tree.resize(N+1,{0,1,});
        tree[0].depth=0;
        set_connect();
        MAX_pow=(int)floor(log2(MAX_depth));
        dp.resize(N+1,vector<int>(MAX_pow+1,-1));
    }
    void set_connect(){
        int a,b;
        for(int i=0;i<N-1;i++){
            std::cin >> a >> b;
            tree[a].edge.push_back(b);
            tree[b].parent=a;
        }
        for(int i=1;i<=N;i++)
            if(tree[i].parent==0){
                dfs(i,1);
                break;
            }
        
    }
    void dfs(int n,int depth){
        tree[n].depth=depth;
        if(depth>MAX_depth)
            MAX_depth=depth;
        for(int i=0;i<tree[n].edge.size();i++){
            dfs(tree[n].edge[i],depth+1);
        }
    }
    void print_tree(){
        for(int i=1;i<=N;i++)
            std::cout << tree[i].parent<<','<<tree[i].depth <<' ';
        std::cout << '\n';
    }
    int DP(int n,int p){
        if(p==0)
            return tree[n].parent;
        if(dp[n][p]!=-1)
            return dp[n][p];
        dp[n][p]=DP(DP(n,p-1),p-1);
        return dp[n][p];
    }
    

    int LCA(int a,int b){
        if(tree[a].depth>tree[b].depth)
            swap(a,b);
        for(int i=MAX_pow;i>=0;i--){
            if(tree[a].depth-tree[DP(b,i)].depth<=0)
                b=DP(b,i);
            if(tree[a].depth==tree[b].depth)
                break;
        }
        if(a==b)
            return a;
        for(int i=MAX_pow;i>=0;i--){
            if(DP(a,i)!=DP(b,i)){
                a=DP(a,i);
                b=DP(b,i);
            }
        }
        return tree[a].parent;
    }
    

};
int main(){
    int n;
    int a,b;
    std::cin >> n;
    for(int i=0;i<n;i++){
        LCA_basic lca;
        std::cin >> a >> b;
        std::cout << lca.LCA(a,b)<<'\n';    
    }

    return 0;
}