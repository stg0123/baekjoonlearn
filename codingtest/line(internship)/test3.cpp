#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
struct _node{
    int parent;
    int depth;
    vector<int> edge;
};
class test3{
private:
    vector<_node> tree;
    vector<vector<int>> sparse;
    int N,MAX_pow;
    int root;
public:
    test3(int n ,vector<vector<int>>& edges ):N(n){
        tree.resize(N+1,{0,0,});
        for(int i=0;i<edges.size();i++){
            tree[edges[i][0]+1].edge.push_back(edges[i][1]+1);
            tree[edges[i][1]+1].edge.push_back(edges[i][0]+1);
        }
        root=1;
        MAX_pow=0;
        maketree(root,0,1);
        MAX_pow=(int)floor(log2(MAX_pow));
        sparse.resize(N+1,vector<int>(MAX_pow+1,-1));
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

    int LCA_length(int a,int b){
        if(tree[a].depth>tree[b].depth)
            swap(a,b);
        int tmp1,tmp2,length=0;
        for(int i=MAX_pow;i>=0;i--){
            tmp1=DP(b,i);
            if(tree[a].depth-tree[tmp1].depth<=0){
                b=tmp1;
                length+=pow(2,i);
            }
            if(tree[a].depth==tree[b].depth)
                break;
        }
        if(a==b)
            return length;
        for(int i=MAX_pow;i>=0;i--){
            tmp1=DP(a,i);
            tmp2=DP(b,i);
            if(tmp1!=tmp2){
                a=tmp1;
                b=tmp2;
                length+=pow(2,i);
            }
        }
        return length+2;
    }
    ll find_sol(){
        ll sol=0;
        for(int i=1;i<=N-1;i++){
            for(int j=i+1;j<=N;j++){
                sol+=LCA_length(i,j)-1;
            }
        }
        return sol*2;
    }



};