#include <iostream>
#include <vector>
#include <algorithm>
struct _node{
    int val;
    _node * next;
};
using namespace std;
class energe{
private:
    _node* root;
    int N;
public:
    energe(){
        std::cin >> N;
        root = new _node;
        set_val();
    }
    void set_val(){
        _node * cur=root;
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            cur->next = new _node({tmp,});
            cur=cur->next;
        }
    }
    int dfs(int depth){
        if(N-depth==2)
            return 0;
        int sol=0;
        _node* cur =root;
        _node* tmp;
        for(int i=2;i<N-depth;i++){
            cur = cur ->next;
            int val = cur->val*cur->next->next->val;
            tmp = cur->next;
            cur->next=cur->next->next;
            sol=max(sol,val +dfs(depth+1));
            cur->next=tmp;
        }
        return sol;
    }
    void find_sol(){
        std::cout << dfs(0) << '\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    energe eg;
    eg.find_sol();

    return 0;
}