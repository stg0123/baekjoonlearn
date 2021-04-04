#include <iostream>
#include <vector>
using namespace std;
struct _node{
    bool finished;
    vector<_node*> child;
};
class trie{
private:
    _node* root;
    int N;
public:
    trie(){
        std::cin >> N;
        root= new _node;
        root->child.resize(10);
    }
    ~ trie(){
        clear_v(root);
    }
    void clear_v(_node* cur){
        for(int i=0;i<cur->child.size();i++){
            if(cur->child[i])
                clear_v(cur->child[i]);
        }
        delete cur;
    }
    void find_sol(){
        _node* cur;
        string str;
        bool flag=false;
        for(int i=0;i<N;i++){
            cur=root;
            std::cin >> str;
            for(int j=0;j<str.size();j++){
                if(cur->child[str[j]-'0']){
                    cur=cur->child[str[j]-'0'];
                    if(j==str.size()-1 || cur->finished==true)
                        flag=true;
                }
                else{
                    cur->child[str[j]-'0']=new _node;
                    cur=cur->child[str[j]-'0'];
                    cur->finished=false;
                    cur->child.resize(10);
                }
                if(j==str.size()-1)
                    cur->finished=true;
            }
        }
        if(flag)
            std::cout << "NO\n";
        else 
            std::cout << "YES\n";
    }

};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        trie t;
        t.find_sol();
    }
    return 0;
}