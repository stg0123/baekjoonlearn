#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct _node{
    int a,b;
    int dis;
};
bool compare(_node& a,_node& b){
    return a.dis<b.dis;
}
class cruscal{
private:
    vector<int> parent;
    vector<_node> info;
    int N,M;
    int min_dis;
public:
    cruscal(){
        std::cin >> N>>M;
        parent.resize(N+1,-1);
        min_dis=0;
        set_val();
    }
    void set_val(){
        int a,b,dis;
        for(int i=0;i<M;i++){
            std::cin >> a >> b >>dis;
            info.push_back({a,b,dis}); 
        }
        sort(info.begin(),info.end(),compare);
    }
    int find(int n){
        if(parent[n]<0)
            return n;
        return parent[n]=find(parent[n]);
    }
    void merge(int a,int b,int dis){
        int p_a=find(a);
        int p_b=find(b);
        if(p_a==p_b)
            return ;
        parent[p_b]=p_a;
        min_dis+=dis;
    }
    void start(){
        for(int i=0;i<info.size();i++){
            merge(info[i].a,info[i].b,info[i].dis);
        }
        std::cout << min_dis;
    }

};
int main(){
    cruscal cr;
    cr.start();   

    return 0;
}