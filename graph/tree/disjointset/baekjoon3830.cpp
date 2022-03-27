#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct _node{
    int parent;
    ll val;
};
int N,M;
_node graph[100010];
int find(int n){
    if(graph[n].parent==-1)
        return n;
    int tmp = graph[n].parent;
    graph[n].parent=find(graph[n].parent);
    graph[n].val += graph[tmp].val;
    return graph[n].parent;
}
void merge(int a,int b,int diff){
    if(a>b){
        ll t = a;
        a=b;
        b=t;
        diff=-diff;
    }
    find(a);find(b);
    ll x = graph[b].val,y= graph[a].val;
    a=find(a),b=find(b);
    graph[b].parent=a;
    graph[b].val=diff+y-x; 
}
void start_query(){
    for(int i=0;i<M;i++){
        char ch;
        std::cin >> ch;
        if(ch=='!'){
            int a,b,diff;
            std::cin >> a >> b >> diff;
            merge(a,b,diff);
        }
        else{
            int a,b;
            std::cin >> a >> b;
            if(find(a)==find(b))
                std::cout << graph[b].val-graph[a].val <<'\n';
            else
                std::cout << "UNKNOWN\n";
        }
    }
}

int main(){
    while(1){
        std::cin >> N >> M;
        if(N==0&&M==0)
            break;
        for(int i=0;i<=N;i++){
            graph[i].parent=-1;
            graph[i].val=0;
        }
        start_query();
    }
    return 0;
}