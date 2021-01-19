#include <iostream>
#include <vector>

#define INF 100000000
using namespace std;

struct node{
    int min_dis;
    vector<pair<int,int>> edge;
};
class velman_ford{
private:
    vector<node> map;
    int SIZE,line_num,holl_num;
public:
    velman_ford(){
        std::cin >> SIZE >>line_num >>holl_num ;
        map.resize(SIZE+1,{INF,});
        set_connect();

    }
    void set_connect(){
        int a,b,dis;
        for(int i=0;i<line_num;i++){
            std::cin >> a >> b >> dis;
            map[a].edge.push_back({b,dis});
            map[b].edge.push_back({a,dis});
        }
        for(int i=0;i<holl_num;i++){
            std::cin >> a>> b >> dis;
            map[a].edge.push_back({b,-dis});
        }

    }
    bool cal_velman_ford(int START){
        map[START].min_dis=0;
        int tmp1,tmp2;
        for(int i=1;i<=SIZE;i++){
            for(int j=1;j<=SIZE;j++){
                for(int l=0;l<map[j].edge.size();l++){
                    tmp1 = map[j].edge[l].first;
                    tmp2 = map[j].edge[l].second;
                    if(map[tmp1].min_dis>map[j].min_dis+tmp2){
                        map[tmp1].min_dis=map[j].min_dis+tmp2;
                        if(i==SIZE||tmp1==START)
                            return true;
                    }

                }
            }
        }
        return false;
    }

};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        velman_ford vel;
        if(vel.cal_velman_ford(1))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }


    return 0;
}