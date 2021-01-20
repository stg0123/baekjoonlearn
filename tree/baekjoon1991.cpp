#include <iostream>
#include <vector>
using namespace std;
struct node{
    char data;
    int left,right;
};
class tree_search{
private:
    vector<node> tree;
    int N;
public:
    tree_search(){
        std::cin >> N;
        for(int i=0;i<=N;i++){
            tree.push_back({(char)(i+64),0,0});
        }
        set_connect();
    }
    void set_connect(){
        char a,left,right;
        for(int i=0;i<N;i++){
            std::cin >> a >> left >> right;
            if(left!='.')
                tree[(int)a-64].left=(int)left-64;
            if(right!='.')
                tree[(int)a-64].right=(int)right-64;
        }
    }

    void preorder(int n){
        if(n==0)
            return ;
        std::cout << tree[n].data;
        preorder(tree[n].left);
        preorder(tree[n].right);
    }
    void inorder(int n){
        if(n==0)
            return ;
        inorder(tree[n].left);
        std::cout << tree[n].data;
        inorder(tree[n].right);
    }
    void postorder(int n){
        if(n==0)
            return ;
        postorder(tree[n].left);
        postorder(tree[n].right);
        std::cout << tree[n].data;
    }


};
int main(){
    tree_search tr;
    tr.preorder(1);
    std::cout << '\n';
    tr.inorder(1);
    std::cout << '\n';
    tr.postorder(1);
    

    return 0;
}