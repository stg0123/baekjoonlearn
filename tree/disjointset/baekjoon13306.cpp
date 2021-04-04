#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct query{
    int idx,a,b;
};
class tree{
private:
    vector<int> parent;
    vector<int> pa_store;
    vector<query> qry;
    int N,M;
public:
    tree(){
        std::cin >> N >> M;
        parent.resize(N+1,-1);
        pa_store.resize(N+1,-1);
        set_val();
    }
    void set_val(){
        int q,a,b;
        for(int i=2;i<=N;i++)
            std::cin >> pa_store[i];
        for(int i=0;i<N-1+M;i++){
            std::cin >> q;
            if(q==0){
                std::cin >> a;
                qry.push_back({q,a,});
            }
            if(q==1){
                std::cin >>a >>b;
                qry.push_back({q,a,b});
            }
        }
    }
    int find(int n){
        if(parent[n]==-1)
            return n;
        return parent[n]=find(parent[n]);
    }
    void start_qry(){
        query cur;
        stack<int> sol;
        while(!qry.empty()){
            cur =qry.back();
            qry.pop_back();
            if(cur.idx==0)
                parent[cur.a]=pa_store[cur.a];
            else{
                if(find(cur.a)==find(cur.b))
                    sol.push(1);
                else
                    sol.push(0);
            }
        }
        while(!sol.empty()){
            if(!sol.top())
                std::cout <<"NO\n";
            else
                std::cout <<"YES\n";
            sol.pop();
        }
    }   

};
int main(){
    tree tr;
    tr.start_qry();
    return 0;
}