#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
struct compare{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return a.second>b.second;
    }
};
class connect{
private:
    vector<vector<int>> map;
    int N;
public:
    connect(){
        std::cin >> N;
        map.resize(N,vector<int>(N));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                std::cin >> map[i][j];
    }
    void prim(){
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        pq.push({0,0});
        vector<bool> visit(N,false);
        pair<int,int> cur,next;
        ll sol=0;
        while(!pq.empty()){
            cur=pq.top();
            pq.pop();
            if(visit[cur.first])
                continue;
            visit[cur.first]=true;
            sol+=cur.second;
            for(int i=0;i<N;i++){
                if(!visit[i])
                    pq.push({i,map[cur.first][i]});
            }
        }
        std::cout << sol;
    }

};
int main(){
    connect cn;
    cn.prim();
    return 0;
}