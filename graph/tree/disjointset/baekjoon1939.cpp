#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct dis{
    int a,b,dis;
};
bool compare(dis& a,dis& b){
    return a.dis>b.dis;
};
class bridge{
private:
    vector<dis> info;
    vector<int> parent;
    int N,M;
    int start,end;
public:
    bridge(){
        std::cin >> N >> M;
        parent.resize(N+1,-1);
        set_info();
        std::cin >> start >> end;
    }
    void set_info(){
        int a,b,dis;
        for(int i=0;i<M;i++){
            std::cin >> a >> b >> dis;
            info.push_back({a,b,dis});
        }
        sort(info.begin(),info.end(),compare);
    }
    int find(int a){
        if(parent[a]==-1)
            return a;
        return parent[a] =find(parent[a]);
    }
    void merge(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb)
            return ;
        parent[pb]=pa;
    }
    int find_sol(){
        for(int i=0;i<info.size();i++){
            merge(info[i].a,info[i].b);
            if(find(start)==find(end))
                return info[i].dis;
        }
        return 0;
    }
};
int main(){
    bridge bdg;
    std::cout << bdg.find_sol()<<'\n';

    return 0;
}