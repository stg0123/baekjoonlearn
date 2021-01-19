#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 200000000
struct compare{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return a.second>b.second;
    }
};  
class floid{
private:
    vector<vector<pair<int,int>>> map;
    vector<vector<int>> min_dis;
    int SIZE;
public:
    floid(){
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
            std::cin >> a>> b>>dis;
            map[a].push_back({b,dis});
        }
    }
    void START_floid(){
        for(int i=1;i<=SIZE;i++){
            dijkstra(i);
        }
        print_min_dis();
    }
    void dijkstra(int START){
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        vector<bool> visit(SIZE+1,false);
        min_dis[START].resize(SIZE+1,INF);
        min_dis[START][START]=0;
        pq.push({START,0});
        int cur,dis,tmp1,tmp2;
        while(!pq.empty()){
            cur=pq.top().first;
            dis=pq.top().second;
            pq.pop();
            if(visit[cur]==true)
                continue;
            visit[cur]=true;
            for(int i=0;i<map[cur].size();i++){
                tmp1=map[cur][i].first;
                tmp2=map[cur][i].second;
                if(min_dis[START][tmp1]>dis+tmp2){
                    min_dis[START][tmp1]=dis+tmp2;
                    pq.push({tmp1,min_dis[START][tmp1]});
                }
            }
        }
    }
    void print_min_dis(){
        for(int i=1;i<min_dis.size();i++){
            for(int j=1;j<min_dis[i].size();j++){
                if(min_dis[i][j]==INF)
                    std::cout << 0<<' ';
                else   
                    std::cout << min_dis[i][j] << ' ';
            }
            std::cout << '\n';                
        }
    }

};
int main(){
    floid f;
    f.START_floid();

    return 0;
}