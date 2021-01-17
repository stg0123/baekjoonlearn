#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 200000000
struct node{
    int min_dis;
    vector<pair<int,int>> edge;
    vector<int> path; 
};
template<typename T>
struct compare{
    bool operator()(T& a,T& b){
        return a.second>b.second;
    }
};
class dijkstra{
private:
    vector<node> dp;
    vector<int> presol;
    int SIZE,line_num,presol_num;
    int START,g,h;
public:
    dijkstra(){
        std::cin >> SIZE >> line_num>>presol_num;
        std::cin >> START >>g >> h;
        dp.resize(SIZE+1,{INF,});
        presol.resize(presol_num);
        
    }
    void set_connect(){
        int a,b,dis;
        for(int i=0;i<line_num;i++){
            std::cin >> a>> b>> dis;
            dp[a].edge.push_back({b,dis});
            dp[b].edge.push_back({a,dis});
        }
        for(int i=0;i<presol_num;i++){
            std::cin >> presol[i];
        }
        sort(presol.begin(),presol.end());
    }

    void cal_dijkstra(){
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare<pair<int,int>>> pq;
        vector<bool> visit(SIZE+1,false);
        dp[START].min_dis=0;
        dp[START].path.push_back(START);
        pq.push({START,0});
        int cur,dis,tmp1,tmp2;
        vector<int> path_tmp;
        while(!pq.empty()){
            cur = pq.top().first;
            dis = pq.top().second;
            pq.pop();
            if(visit[cur]==true)
                continue;
            visit[cur]=true;
            for(int i=0;i<dp[cur].edge.size();i++){
                tmp1 = dp[cur].edge[i].first;
                tmp2 = dp[cur].edge[i].second;
                if(visit[tmp1]==false){
                    if(dp[tmp1].min_dis>dis+tmp2){
                        dp[tmp1].min_dis=dis+tmp2;
                        dp[tmp1].path=dp[cur].path;
                        dp[tmp1].path.push_back(tmp1);
                        pq.push({tmp1,dp[tmp1].min_dis});
                    }
                    else if(dp[tmp1].min_dis==dis+tmp2){
                        path_tmp = dp[cur].path;
                        path_tmp.push_back(tmp1);
                        for(int j=0;j<path_tmp.size()-1;j++){
                            if(path_tmp[j]==g&&path_tmp[j+1]==h){
                                dp[tmp1].path = path_tmp;
                                break;
                            }
                            else if(path_tmp[j]==h&&path_tmp[j+1]==g){
                                dp[tmp1].path = path_tmp;
                                break;
                            }
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<presol.size();i++){
            if(dp[presol[i]].min_dis==INF)
                continue;
            path_tmp = dp[presol[i]].path;
            for(int j=0;j<path_tmp.size()-1;j++){
                if(path_tmp[j]==g&&path_tmp[j+1]==h){
                    std::cout <<presol[i]<<' '; 
                    break;
                }
                else if(path_tmp[j]==h&&path_tmp[j+1]==g){
                    std::cout <<presol[i]<<' '; 
                    break;
                }
            }
        }
        std::cout << '\n';
    }

};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        dijkstra di;
        di.set_connect();
        di.cal_dijkstra();

    }


    return 0;
}