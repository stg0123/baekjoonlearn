#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct _node{
    int weight;
    int pre;
    vector<int> next_e,pre_e;
    
};
class work{
private:
    vector<_node> map;
    vector<int> dp;
    int N;
public:
    work(){
        std::cin >> N;
        map.resize(N+1);
        dp.resize(N+1);
        set_val();
    }
    void set_val(){
        int a,n;
        for(int i=1;i<=N;i++){
            std::cin >> a >> n;
            map[i].weight=a;
            map[i].pre=n;
            for(int j=0;j<n;j++){
                std::cin >> a;
                map[a].next_e.push_back(i);
                map[i].pre_e.push_back(a);
            }
        }
    }
    void topolgy_sort(){
        queue<int> q;    
        for(int i=1;i<=N;i++){
            if(map[i].pre==0){
                q.push(i);
                dp[i]=map[i].weight;
            }
        }
        int sol=0;
        int cur;
        while(!q.empty()){
            cur=q.front();
            q.pop();
            sol=max(sol,dp[cur]);
            for(int next : map[cur].next_e){
                if(--(map[next].pre)==0){    
                    for(int p : map[next].pre_e)
                        dp[next]=max(dp[p],dp[next]);
                    dp[next]+=map[next].weight;
                    q.push(next);
                }
            }
        }
        std::cout << sol << '\n';
    }   


};
int main(){
    work w;
    w.topolgy_sort();
    return 0;
}