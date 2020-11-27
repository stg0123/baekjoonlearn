#include <iostream>
#include <vector>
//10:10
using namespace std;
typedef struct node{
    int data;
    bool visit;
    vector<node*> edge;

}node;
class warm{
private:
    vector<node> map;
    int N;
public:
    warm(int n):N(n){
        map.resize(n+1);
        for(int i=1;i<=n;i++){
            map[i].data=i;
            map[i].visit=false;
        }

    };
    void set_conc(){
        int k,a,b;
        std::cin >>k;
        for(int i=1;i<=k;i++){
            std::cin  >> a >> b;
            map[a].edge.push_back(&map[b]);
            map[b].edge.push_back(&map[a]);
        }
    };
    void dfs(int start,int& degree){
        if(map[start].visit==true)
            return ;
        map[start].visit=true;
        degree+=1;
        for(int i=0;i<map[start].edge.size();i++){
            dfs(map[start].edge[i]->data,degree);
        }
    }

};

int main(){
    int n,degree=0;
    std::cin >> n;
    warm w(n);
    w.set_conc();
    w.dfs(1,degree);
    std::cout << degree-1;
    return 0;
}
