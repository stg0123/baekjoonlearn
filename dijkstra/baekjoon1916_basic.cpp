#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
struct _node{
    int min_dis;
    vector<pair<int,int>> path;
};
struct compare{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return a.second>b.second;
    };
};
class dijkstra_basic{
private:
    vector<_node> map;
    int N,M;
public:
    dijkstra_basic(){
        std::cin >> N >> M;
        map.resize(N+1,{INF,});
        set_val();
    }
    void set_val(){
        int a,b,dis;
        for(int i=0;i<M;i++){
            std::cin >> a >> b>>dis;
            map[a].path.push_back({b,dis});
        }
    }
    void dijkstra(){
        int START,END;
        std::cin >> START >> END;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq; 
        pq.push({START,0});
        map[START].min_dis=0;
        pair<int,int> cur,next;
        while(!pq.empty()){
            cur=pq.top();
            pq.pop();
            if(map[cur.first].min_dis<cur.second)
                continue;
            
            for(int i=0;i<map[cur.first].path.size();i++){
                next=map[cur.first].path[i];
                if(map[next.first].min_dis>cur.second+next.second){
                    map[next.first].min_dis=cur.second+next.second;
                    pq.push({next.first,map[next.first].min_dis});
                }
            }
        }
        std::cout << map[END].min_dis ;

    }



};
int main(){
    dijkstra_basic db;
    db.dijkstra();
    return 0;
}