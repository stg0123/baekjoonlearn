#include <iostream>
#include <vector>
using namespace std;
struct _node{
    int parent;
    vector<int> child;
    int sub_num;
};
class tree_dp{
private:
    vector<_node> tree;
    int N,root,M;
public:
    tree_dp(){
        std::cin >> N>>root >> M;
        tree.resize(N+1);
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<N-1;i++){
            std::cin >> a >> b;
            tree[a].child.push_back(b);
            tree[b].child.push_back(a);
        }
    }
    void set_tree(){
        maketree(root,-1);
        set_subnum(root);
    }
    void maketree(int cur,int parent){
        tree[cur].parent=parent;
        int tmp=-1;
        for(int i=0;i<tree[cur].child.size();i++){
            if(tree[cur].child[i]==parent){
                tmp=i;
                continue;
            }
            maketree(tree[cur].child[i],cur);
        }
        if(tmp!=-1)
            tree[cur].child.erase(tree[cur].child.begin()+tmp);
    }
    int set_subnum(int n){
        tree[n].sub_num=1;
        for(int i=0;i<tree[n].child.size();i++){
            tree[n].sub_num +=set_subnum(tree[n].child[i]);
        }
        return tree[n].sub_num;
    }
    void print_subnum(){
        int n;
        for(int i=0;i<M;i++){
            std::cin >> n;
            std::cout << tree[n].sub_num<<'\n';
        }
    }
};
int main(){
    tree_dp tr;
    tr.set_tree();
    tr.print_subnum();

    return 0;
}