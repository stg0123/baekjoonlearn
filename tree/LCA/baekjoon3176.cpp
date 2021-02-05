#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct _node{
    pair<int,int> parent;
    int depth;
    vector<pair<int,int>> edge;
};
struct _data{
    int parent;
    int MAX_dis;
    int MIN_dis;
};
class line_space{
private:
    vector<_node> tree;
    vector<vector<_data>> sparse;
    int N,MAX_DIS,MIN_DIS;
    int root,MAX_pow;
public:
    line_space(){
        std::cin >> N;
        tree.resize(N+1);
        tree[0].parent={0,0};
        tree[0].depth=0;
        root=1;
        MAX_pow=(int)floor(log2(100000));
        MAX_DIS=0;
        MIN_DIS=0;
        set_connect();
        sparse.resize(N+1,vector<_data>(MAX_pow+1,{0,0,0}));
        maketree(root,{0,0},1);
        set_sparse();
    }
    void print_spar(){
        for(int i=1;i<=N;i++)
            std::cout << sparse[i][0].parent << ','<<sparse[i][0].MIN_dis<<','<<sparse[i][0].MAX_dis<<' ';
        std::cout << '\n';
    }
    void set_connect(){
        int a,b,dis;
        for(int i=0;i<N-1;i++){
            std::cin >> a>>b>>dis;
            tree[a].edge.push_back({b,dis});
            tree[b].edge.push_back({a,dis});
            MAX_DIS=max(MAX_DIS,dis);
        }

    }
    void set_sparse(){
        for(int i=1;i<=MAX_pow;i++)
            for(int j=1;j<=N;j++){
                sparse[j][i].MAX_dis=max(sparse[j][i-1].MAX_dis,sparse[sparse[j][i-1].parent][i-1].MAX_dis);
                sparse[j][i].MIN_dis=min(sparse[j][i-1].MIN_dis,sparse[sparse[j][i-1].parent][i-1].MIN_dis);
                sparse[j][i].parent=sparse[sparse[j][i-1].parent][i-1].parent;
            }
    }
    void maketree(int cur,pair<int,int> parent,int depth){
        tree[cur].parent=parent;
        sparse[cur][0].parent=parent.first;
        sparse[cur][0].MAX_dis=parent.second;
        sparse[cur][0].MIN_dis=parent.second;
        tree[cur].depth=depth;
        pair<int,int> tmp;
        int erase_num=-1;
        for(int i=0;i<tree[cur].edge.size();i++){
            tmp = tree[cur].edge[i];
            if(tmp.first==parent.first){
                erase_num=i;
                continue;
            }
            maketree(tmp.first,{cur,tmp.second},depth+1);
        }
        if(erase_num!=-1)
            tree[cur].edge.erase(tree[cur].edge.begin()+erase_num);
    }

    void LCA(int a,int b){
        int sol_min=MAX_DIS,sol_max=MIN_DIS;
        if(tree[a].depth>tree[b].depth)
            swap(a,b);
        for(int i=MAX_pow;i>=0;i--){
            if(tree[a].depth-tree[sparse[b][i].parent].depth<=0){
                sol_min=min(sol_min,sparse[b][i].MIN_dis);
                sol_max=max(sol_max,sparse[b][i].MAX_dis);
                b=sparse[b][i].parent;
            }
        }
        if(a==b){
            std::cout << sol_min << ' '<<sol_max <<'\n';
            return ;
        }
        for(int i=MAX_pow;i>=0;i--){
            if(sparse[a][i].parent!=sparse[b][i].parent){
                sol_min=min(sol_min,sparse[a][i].MIN_dis);
                sol_max=max(sol_max,sparse[a][i].MAX_dis);
                sol_min=min(sol_min,sparse[b][i].MIN_dis);
                sol_max=max(sol_max,sparse[b][i].MAX_dis);
                a=sparse[a][i].parent;
                b=sparse[b][i].parent;
            }
        }
        sol_min=min(sol_min,sparse[a][0].MIN_dis);
        sol_max=max(sol_max,sparse[a][0].MAX_dis);
        sol_min=min(sol_min,sparse[b][0].MIN_dis);
        sol_max=max(sol_max,sparse[b][0].MAX_dis);
        a=sparse[a][0].parent;
        b=sparse[b][0].parent;

        std::cout << sol_min << ' '<< sol_max <<'\n';

    }
};
int main(){
    line_space ls;
    int n,a,b;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> a>> b;
        ls.LCA(a,b);
    }

    return 0;
}