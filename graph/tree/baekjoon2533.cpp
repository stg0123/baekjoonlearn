#include <iostream>
#include <vector>
using namespace std;
struct _node{
    int parent;
    int min_cnt;
    vector<int> child;
};
class early_adaptor{
private:
    vector<_node> tree;
    vector<vector<int>> dp;
    int N,root;
public:
    early_adaptor(){
        std::cin >> N;
        tree.resize(N+1);
        root=1;
        set_connect();
        maketree(root,-1);
        dp.resize(N+1,vector<int>(2,-1));
    }
    void print_tree(){
        for(int i=1;i<=N;i++)
            std::cout << tree[i].parent<<' ';
        std::cout << '\n';
    }
    void set_connect(){
        int a,b;
        for(int i=0;i<N-1;i++){
            std::cin >> a >> b;
            tree[a].child.push_back(b);
            tree[b].child.push_back(a);
        }  
    
    }
    void maketree(int cur,int parent){
        tree[cur].parent=parent;
        int tmp,erase_idx=-1;
        for(int i=0;i<tree[cur].child.size();i++){
            tmp=tree[cur].child[i];
            if(tmp==parent){
                erase_idx=i;
                continue;
            }
            maketree(tmp,cur);
        }
        if(erase_idx!=-1)
            tree[cur].child.erase(tree[cur].child.begin()+erase_idx);
    }
    void start_DP(){
        std::cout << min(DP(root,0),DP(root,1));

    }
    int DP(int idx,int n){
        if(dp[idx][n]!=-1)
            return dp[idx][n];
        dp[idx][n]=0;
        int tmp;
        if(n==0){
            for(int i=0;i<tree[idx].child.size();i++){
                tmp=tree[idx].child[i];
                dp[idx][n]+=DP(tmp,1);
            }
        }
        else if(n==1){
            for(int i=0;i<tree[idx].child.size();i++){
                tmp=tree[idx].child[i];
                dp[idx][n]+=min(DP(tmp,1),DP(tmp,0));
            }
            dp[idx][n]++;
        }
        return dp[idx][n];
    }
    
};
int main(){
    early_adaptor ea;
    ea.start_DP();

    return 0;
}