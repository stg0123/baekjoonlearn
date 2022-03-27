#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
struct _node{
    pair<int,ll> parent;
    int depth;
    ll sum_dis;
    vector<pair<int,ll>> edge;
};
class tree_query{
private:
    vector<_node> tree;
    vector<vector<int>> sparse;
    int N,MAX_pow;
    int root;
public:
    tree_query(){
        std::cin >> N;
        tree.resize(N+1);
        MAX_pow=(int)floor(log2(100000));
        root=1;
        sparse.resize(N+1,vector<int>(MAX_pow+1,0));
        set_connect();
        maketree(root,{0,0},1,0);
        set_sparse();
    }
    void set_connect(){
        int a,b,dis;
        for(int i=0;i<N-1;i++){
            std::cin >> a>>b>>dis;
            tree[a].edge.push_back({b,dis});
            tree[b].edge.push_back({a,dis});
        }
    }
    void maketree(int cur,pair<int,ll> parent,int depth,ll distance){
        tree[cur].parent=parent;
        tree[cur].sum_dis=distance;
        tree[cur].depth=depth;
        sparse[cur][0]=parent.first;
        pair<int,ll> tmp;
        int erase_num=-1;
        for(int i=0;i<tree[cur].edge.size();i++){
            tmp=tree[cur].edge[i];
            if(tmp.first==parent.first){
                erase_num=i;
                continue;
            }
            maketree(tmp.first,{cur,tmp.second},depth+1,distance+tmp.second);
        }
        if(erase_num!=-1)
            tree[cur].edge.erase(tree[cur].edge.begin()+erase_num);
        
    }
    void set_sparse(){
        for(int i=1;i<=MAX_pow;i++)
            for(int j=1;j<=N;j++)
                sparse[j][i]=sparse[sparse[j][i-1]][i-1];
    }
    int LCA(int a,int b){
        if(tree[a].depth>tree[b].depth)
            swap(a,b);
        for(int i=MAX_pow;i>=0;i--){
            if(tree[a].depth-tree[sparse[b][i]].depth<=0)
                b=sparse[b][i];
            if(tree[a].depth==tree[b].depth)
                break;
        }
        if(a==b)
            return a;
        for(int i=MAX_pow;i>=0;i--){
            if(sparse[a][i]!=sparse[b][i]){
                a=sparse[a][i];
                b=sparse[b][i];
            }
        }
        return sparse[a][0];
    }
    int query2(int a,int b,int c){
        int lca=LCA(a,b);
        int leftdepth= tree[a].depth-tree[lca].depth;
        int rightdepth=tree[b].depth-tree[lca].depth;
        c--;
        if(c<=leftdepth){
            for(int i=MAX_pow;i>=0;i--){
                if(c>=(1<<i)){
                    c-=(1<<i);
                    a=sparse[a][i];
                }
                if(c==0)
                    break;
            }
            return a;
        }
        else{
            c=rightdepth-(c-leftdepth);
            for(int i=MAX_pow;i>=0;i--){
                if(c>=(1<<i)){
                    c-=(1<<i);
                    b=sparse[b][i];
                }
                if(c==0)
                    break;
            }
            return b;
        }

    }

    void start_query(){
        int oper,a,b;
        std::cin >> oper >> a >> b;
        if(oper==1){
            int tmp= LCA(a,b);
            std::cout << tree[a].sum_dis+tree[b].sum_dis-(tree[tmp].sum_dis*2)<<'\n';
        }
        else if(oper==2){
            int c;
            std::cin >> c;
            std::cout << query2(a,b,c)<<'\n';
        }
    }

};
int main(){
    tree_query tq;
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        tq.start_query();
    }
    

    return 0;
}