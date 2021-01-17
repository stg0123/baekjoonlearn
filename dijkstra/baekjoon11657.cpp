#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 100000000
struct node{
    long min_dis;
    vector<pair<int,int>> edge;
};
class velman_ford{
private:
    vector<node> map;
    int SIZE;
public:
    velman_ford(){
        std::cin >> SIZE;
        map.resize(SIZE+1,{INF,});
        set_connect();
    }
    void set_connect(){
        int a,b,dis;
        int n;
        std::cin >> n;
        for(int i=0;i<n;i++){
            std::cin >> a >> b>> dis;
            map[a].edge.push_back({b,dis});
        }
    }
    bool cal_velman_ford(int START){
        map[START].min_dis=0;
        int tmp1,tmp2;
        int cur=START;
        for(int i=1;i<=SIZE;i++){
            for(int j=1;j<=SIZE;j++){
                if(map[j].min_dis==INF)
                    continue;
                for(int l=0;l<map[j].edge.size();l++){
                    tmp1=map[j].edge[l].first;    
                    tmp2=map[j].edge[l].second;
                    if(map[tmp1].min_dis>map[j].min_dis+tmp2){
                        map[tmp1].min_dis=map[j].min_dis+tmp2;
                        if(i==SIZE)
                            return false;
                    }
                }
            }
        }
        return true;
    }
    void start_velman_ford(){
        if(cal_velman_ford(1)){
            for(int i=2;i<=SIZE;i++){
                if(map[i].min_dis==INF)
                    std::cout << -1<<'\n';
                else
                    std::cout << map[i].min_dis << '\n';
            }
        }
        else
            std::cout << -1<<'\n';

    }

};
int main(){
    velman_ford vel;
    vel.start_velman_ford();

    return 0;
}