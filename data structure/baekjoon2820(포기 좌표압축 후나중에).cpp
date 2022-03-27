#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct _node{
    int pay;
    int lazy=0;
    vector<int> child;
};
class car_factory{
private:
    vector<_node> tree;
    int N,M;
    int root =1;
public: 
    car_factory(){
        std::cin >> N >> M;
        tree.resize(N+1);
        set_val();
    }
    void set_val(){
        int a;
        std::cin >> tree[1].pay;
        for(int i=2;i<=N;i++){
            std::cin >> tree[i].pay >> a;
            tree[a].child.push_back(i);
        }
    }
    void propagation(int node){
        for(int i : tree[node].child){
            if(tree[node].lazy){
                tree[i].pay+=tree[node].lazy;
                tree[i].lazy+=tree[node].lazy;
            }
            propagation(i);
        }
    }
    void start_query(){
        queue<int> offline_query;
        char q;
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> q;
            if(q=='p'){
                std::cin >> a >> b;
                tree[a].lazy+=b;
            }
            else{
                std::cin >> a;
                offline_query.push(a);   
            }
        }
        propagation(1);
        while(!offline_query.empty()){
            std::cout << tree[offline_query.front()].pay << '\n';
            offline_query.pop();
        }
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    car_factory cf;
    cf.start_query();
    return 0;
}