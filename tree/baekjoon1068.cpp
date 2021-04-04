#include <iostream>
#include <vector>
using namespace std;
struct _node{
    vector<int> child;
};
class leafind{
private:
    vector<_node> tree;
    int N;
    int root,ex;
    int sol=0;
public:
    leafind(){
        std::cin >> N;
        tree.resize(N);
        set_val();
    }
    void set_val(){
        int p;
        for(int i=0;i<N;i++){
            std::cin >> p;
            if(p==-1)
                root=i;
            else
                tree[p].child.push_back(i);
        }
        std::cin >>ex;
    }
    void dfs(int n){
        if(tree[n].child.size()==0){
            sol++;
            return ;
        }
        if(tree[n].child.size()==1){
            if(tree[n].child[0]==ex){
                sol++;
                return ;
            }
        }
        for(int i=0;i<tree[n].child.size();i++){
            if(tree[n].child[i]!=ex)
                dfs(tree[n].child[i]);
        }
    }
    void find_sol(){
        if(root==ex){
            std::cout << 0;
            return ;
        }
        dfs(root);
        std::cout << sol;
    }
};
int main(){
    leafind lf;
    lf.find_sol();
    return 0;
}