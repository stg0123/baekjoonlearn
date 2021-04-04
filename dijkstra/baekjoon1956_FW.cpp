#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 100000000
struct compare{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return a.second>b.second;
    }
};

class exercise{
private:
    vector<vector<pair<int,int>>> map;
    vector<vector<int>> min_dis;
    int SIZE;
public:
    exercise(){
        std::cin >> SIZE;
        map.resize(SIZE+1);
        min_dis.resize(SIZE+1);
        set_connect();
    }
    void set_connect(){
        int n;
        std::cin >> n;
        int a,b,dis;
        for(int i=0;i<n;i++){
            std::cin >> a >> b>> dis;
            map[a].push_back({b,dis});
        }
    }

    int dijkstra(int START){
        min_dis[START].resize(SIZE+1,INF);
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        pq.push({START,0});
        int cur,c_dis;
        pair<int,int> tmp;
        while(!pq.empty()){
            cur = pq.top().first;
            c_dis = pq.top().second;
            pq.pop();
            if(min_dis[START][cur]<c_dis)
                continue;
            for(int i=0;i<map[cur].size();i++){
                tmp= map[cur][i];
                if(min_dis[START][tmp.first]>c_dis+tmp.second){
                    min_dis[START][tmp.first]=c_dis+tmp.second;
                    pq.push({tmp.first,c_dis+tmp.second});
                }
            }
        }
        return min_dis[START][START];
    }

    void find_min(){
        int sol=INF;
        for(int i=1;i<SIZE;i++){
            sol=min(sol,dijkstra(i));
        }
        if(sol==INF)
            std::cout << -1 << '\n';
        else
            std::cout << sol << '\n';
    }

};
int main(){
    exercise ex;
    ex.find_min();

    return 0;
}