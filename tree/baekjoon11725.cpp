#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node{
    int ancestor;
    vector<int> child;
};
class arr_tree{
private:
    vector<node> tree;
    int N;
public:
    arr_tree(){
        std::cin >> N;
        tree.resize(N+1,{0,});
    };
    void connect(){
        int a,b;
        for(int i=1;i<N;i++){
            std::cin >> a >> b;
            tree[b].child.push_back(a);
            tree[a].child.push_back(b);
        }
        queue<int> q;
        q.push(1);
        tree[1].ancestor=1;
        int cur,tmp;
        while(!q.empty()){
            cur=q.front();
            q.pop();
            for(int i=0;i<tree[cur].child.size();i++){
                tmp = tree[cur].child[i];
                if(tree[tmp].ancestor==0){
                    tree[tmp].ancestor=cur;
                    q.push(tmp);
                }
            }
        }
        print_ancestor();
    }

    void print_ancestor(){
        for(int i=2;i<=N;i++){
            std::cout << tree[i].ancestor<<'\n';
        }
        
    }



};
int main(){
    arr_tree ar;
    ar.connect();

    return 0;
}