#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
struct _node{
    float x,y;
};
struct compare{
    bool operator()(pair<int,float>& a,pair<int,float>& b){
        return a.second>b.second;
    }
};
class prim{
private:
    vector<_node> point;
    int N;
public:
    prim(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        float a,b;
        for(int i=0;i<N;i++){
            std::cin >> a>> b;
            point.push_back({a,b});
        }
    }
    float distance(_node a,_node b){
        float dx=a.x-b.x;
        float dy=a.y-b.y;
        return sqrt(dx*dx+dy*dy);
    };
    void prim_al(){
        int start= 0;
        priority_queue<pair<int,float>,vector<pair<int,float>>,compare> pq;
        vector<bool> visit(N,false);
        pq.push({start,0});
        int cur;
        float c_dis,sol=0;
        while(!pq.empty()){
            cur=pq.top().first;
            c_dis=pq.top().second;
            pq.pop();
            if(visit[cur]==true)
                continue;
            visit[cur]=true;
            sol+=c_dis;
            for(int i=0;i<N;i++){
                if(visit[i]==false)
                    pq.push({i,distance(point[cur],point[i])});
            }
        }
        printf("%.2f",sol);
    }

};
int main(){
    prim pr;
    pr.prim_al();

    return 0;
}