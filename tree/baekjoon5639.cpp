#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct _node{
    int data;
    _node* left;
    _node* right;
};
class BST{
private:
    _node* root;
    vector<int> preorder;
public:
    BST(){
        set_preorder();
        root=make_tree(0,preorder.size()-1);
    }
    void set_preorder(){
        int a;
        while(std::cin >> a){
            preorder.push_back(a);
        }
    }
    void print_vector(){
        for(int i=0;i<preorder.size();i++)
            std::cout << preorder[i]<<' ';
        std::cout << '\n';

    }
    _node* make_tree(int start,int end){
        if(start>end)
            return NULL;
        _node* tmp=new _node;
        tmp->data=preorder[start];
        int i=start;
        while(i<=end){
            if(preorder[i]>preorder[start])
                break;
            i++;
        }
        tmp->left=make_tree(start+1,i-1);
        tmp->right=make_tree(i,end);

        return tmp;
    }

    void start_postorder(){
        postorder(root);

    }
    void postorder(_node* node ){
        if(node==NULL)  
            return ;

        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << '\n';

    }
};
int main(){
    BST b;
    b.start_postorder();

    return 0;
}