#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct _node{
    string val;
    vector<_node*> edge;
};
bool compare(_node* a,_node* b){
    return a->val<b->val;
}
class TRIE{
private:
    _node* root;
    int N;
public:
    TRIE(){
        root=new _node;
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int n;
        vector<string> str;
        for(int i=0;i<N;i++){
            std::cin >> n;
            str.clear();
            str.resize(n);
            for(int j=0;j<n;j++)
                std::cin >> str[j];
            insert(str);
        }
    }
    void insert(vector<string> str){
        _node* cur =root;
        bool flag;
        for(int i=0;i<str.size();i++){
            flag=false;
            for(int j=0;j<(cur->edge.size());j++){
                if(cur->edge[j]->val==str[i]){
                    cur=cur->edge[j];
                    flag=true;
                    break;
                }
            }
            if(!flag){
                _node * tmp = new _node({str[i],});
                cur->edge.push_back(tmp);
                cur=tmp;
            }
        }
    }
    void start_print(){
        sort(root->edge.begin(),root->edge.end(),compare);
        for(int i=0;i<root->edge.size();i++)
            print_trie(root->edge[i],0);
    }

    void print_trie(_node* cur,int deg){
        for(int i=0;i<deg;i++)
            std::cout << "--";
        std::cout << cur->val<<'\n';
        sort(cur->edge.begin(),cur->edge.end(),compare);
        for(int i=0;i<cur->edge.size();i++)
            print_trie(cur->edge[i],deg+1);
    }

};
int main(){
    TRIE tr;
    tr.start_print();
    return 0;
}