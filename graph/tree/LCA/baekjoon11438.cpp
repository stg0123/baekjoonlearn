#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct _node{
    int parent;
    int depth;
    vector<int> edge;
};
class LCA_2{
private:
    vector<_node> tree;
    vector<vector<int>> sparse;
    int N,MAX_pow;
    int root;
public:
    LCA_2(){
        std::cin >> N;
        tree.resize(N+1,{0,0,});
        set_connect();
        root=1;
        MAX_pow=0;
        maketree(root,0,1);
        MAX_pow=(int)floor(log2(MAX_pow));
        sparse.resize(N+1,vector<int>(MAX_pow+1,-1));
    }
    void set_connect(){
        int a,b;
        for(int i=0;i<N-1;i++){
            std::cin >> a >> b;
            tree[a].edge.push_back(b);
            tree[b].edge.push_back(a);
        }
    }
    void maketree(int cur,int parent,int depth){
        tree[cur].parent=parent;
        tree[cur].depth=depth;
        if(depth>MAX_pow)
            MAX_pow=depth;
        int tmp,erase_num=-1;
        for(int i=0;i<tree[cur].edge.size();i++){
            tmp=tree[cur].edge[i];
            if(tmp==parent){
                erase_num =i;
                continue;
            }
            maketree(tmp,cur,depth+1);
        }
        if(erase_num!=-1)
            tree[cur].edge.erase(tree[cur].edge.begin()+erase_num);
    }
    int DP(int n,int pow){
        if(pow==0)
            return tree[n].parent;
        if(sparse[n][pow]!=-1)
            return sparse[n][pow];
        sparse[n][pow]=DP(DP(n,pow-1),pow-1);
        return sparse[n][pow];

    }

    int LCA(int a,int b){
        if(tree[a].depth>tree[b].depth)
            swap(a,b);
        int tmp1,tmp2;
        for(int i=MAX_pow;i>=0;i--){
            tmp1=DP(b,i);
            if(tree[a].depth-tree[tmp1].depth<=0)
                b=tmp1;
            if(tree[a].depth==tree[b].depth)
                break;
        }
        if(a==b)
            return a;
        for(int i=MAX_pow;i>=0;i--){
            tmp1=DP(a,i);
            tmp2=DP(b,i);
            if(tmp1!=tmp2){
                a=tmp1;
                b=tmp2;
            }
        }
        return tree[a].parent;
    }
};
int main(){
    LCA_2 lca;
    int n,a,b;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >>a >> b;
        std::cout <<lca.LCA(a,b)<<'\n';
    }

    return 0;
}