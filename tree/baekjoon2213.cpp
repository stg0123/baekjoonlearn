#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct _node{
    int parent;
    int weight;
    vector<int> child;
};
struct memo{
    int max_weight;
    vector<int> path;
};
class max_independent_set{
private:
    vector<_node> tree;
    vector<vector<memo>> dp;
    int N,root;
public:
    max_independent_set(){
        std::cin >> N;
        tree.resize(N+1);
        root=1;
        set_weight();
        set_connect();
        maketree(root,-1);
        dp.resize(N+1,vector<memo>(2,{-1,}));
    }
    void set_weight(){
        for(int i=1;i<=N;i++){
            std::cin >> tree[i].weight;
        }
    }
    void set_connect(){
        int a,b;
        for(int i=0;i<N-1;i++){
            std::cin >> a >> b;
            tree[a].child.push_back(b);
            tree[b].child.push_back(a);
        }
    }
    void print_parent(){
        for(int i=1;i<=N;i++){
            std::cout << tree[i].parent << ' '; 
        }
        std::cout << '\n';
    }
    void maketree(int cur,int parent){
        tree[cur].parent=parent;
        int tmp,erase_idx=-1;
        for(int i=0;i<tree[cur].child.size();i++){
            tmp=tree[cur].child[i];
            if(tmp==parent){
                erase_idx =i;
                continue;
            }
            maketree(tmp,cur);
        }
        if(erase_idx!=-1)
            tree[cur].child.erase(tree[cur].child.begin()+erase_idx);
    }
    void start_DP(){
        memo tmp1=DP(root,0);
        memo tmp2=DP(root,1);
        if(tmp1.max_weight>tmp2.max_weight){
            std::cout << tmp1.max_weight<<"\n";
            sort(tmp1.path.begin(),tmp1.path.end());
            for(int i=0;i<tmp1.path.size();i++)
                std::cout << tmp1.path[i] << ' ';
        }
        else{
            std::cout << tmp2.max_weight<<"\n";
            sort(tmp2.path.begin(),tmp2.path.end());
            for(int i=0;i<tmp2.path.size();i++)
                std::cout << tmp2.path[i] << ' ';
            
        }

    }
    memo DP(int idx,int n){
        if(dp[idx][n].max_weight!=-1)
            return dp[idx][n];
        memo tmp1,tmp2;
        dp[idx][n].max_weight=0;
        if(n==0){
            for(int i=0;i<tree[idx].child.size();i++){
                tmp1 =DP(tree[idx].child[i],1);
                tmp2 =DP(tree[idx].child[i],0);
                if(tmp1.max_weight>tmp2.max_weight){
                    dp[idx][n].max_weight+=tmp1.max_weight;
                    for(int j=0;j<tmp1.path.size();j++)
                        dp[idx][n].path.push_back(tmp1.path[j]);
                }
                else{
                    dp[idx][n].max_weight+=tmp2.max_weight;
                    for(int j=0;j<tmp2.path.size();j++)
                        dp[idx][n].path.push_back(tmp2.path[j]);
                }
            }
        }
        else if (n==1){
            for(int i=0;i<tree[idx].child.size();i++){
                tmp1 =DP(tree[idx].child[i],0);
                dp[idx][n].max_weight += tmp1.max_weight;
                for(int j=0;j<tmp1.path.size();j++)
                    dp[idx][n].path.push_back(tmp1.path[j]);
            }
            dp[idx][n].max_weight+=tree[idx].weight;
            dp[idx][n].path.push_back(idx);
        }
        return dp[idx][n];
    }

};
int main(){
    max_independent_set mis;
    mis.start_DP();
    return 0;
}