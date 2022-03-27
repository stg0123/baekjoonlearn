#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct _node{
    int parent;
    vector<int> edge;  
};
class find_tree{
private:
    vector<_node> tree;
    vector<bool> visit;
    int N,M;
public:
    find_tree(int n,int m):N(n),M(m){
        tree.resize(N+1);
        visit.resize(N+1,false);
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a>> b;
            tree[a].edge.push_back(b);
            tree[b].edge.push_back(a);
        }
    }
    int bfs(int START){
        if(visit[START]==true)
            return 0;
        queue<int> q;
        q.push(START);
        visit[START]=true;
        int cur,tmp;
        while(!q.empty()){
            cur= q.front();
            q.pop();
            for(int i=0;i<tree[cur].edge.size();i++){
                tmp=tree[cur].edge[i];
                if(visit[tmp]==false){                    
                    visit[tmp]=true;
                    tree[tmp].parent=cur;
                    q.push(tmp);   
                }
                else if(tree[cur].parent!=tmp)
                    return 0;
            }
        }
        return 1;
    }
    int find(){
        int sol=0;
        for(int i=1;i<=N;i++)
            sol+=bfs(i);
        return sol;
    }


};
int main(){
    int a,b,tmp,CASE=0;
    while(1){
        CASE++;
        std::cin >> a>> b;
        if(a==0&&b==0)
            break;
        find_tree tr(a,b);
        tmp=tr.find();
        std::cout << "Case " <<CASE <<": ";
        if(tmp==0)
            std::cout<< "No trees.\n";
        else if(tmp == 1)
            std::cout<< "There is one tree.\n";
        else if(tmp>1)
            std::cout<<"A forest of "<<tmp <<" trees.\n";
    }

    return 0;
}

