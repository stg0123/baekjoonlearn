#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;
typedef long long ll;
struct _node{
    int capacity;
    int flow;
};
int CCW(pair<ll,ll>& a,pair<ll,ll>& b,pair<ll,ll>& c){
    ll tmp=a.first*b.second-a.second*b.first+b.first*c.second-b.second*c.first+c.first*a.second-c.second*a.first;
    if(tmp>0)
        return 1;
    else if(tmp<0)
        return -1;
    else if(tmp ==0)
        return 0;
};
struct line{
    pair<ll,ll> start,end;
};
class Tom_Jarry{
private:
    vector<vector<_node>> cf;
    vector<vector<int>> path;
    vector<int> prev;
    vector<line> map;
    int n,k,h,m;
public:
    Tom_Jarry(){
        std::cin >> n >> k >> h >> m;
        path.resize(h+m+2);
        prev.resize(h+m+2);
        cf.resize(h+m+2,vector<_node>(h+m+2));
        set_val();

    }
    void set_val(){
        ll x1,y1,x2,y2;
        for(int i=0;i<n;i++){
            std::cin >> x2 >> y2;
            if(i!=0)
                map.push_back({{x1,y1},{x2,y2}});
            x1=x2;
            y1=y2;
        }
        map.push_back({{x1,y1},map[0].start});
        vector<pair<ll,ll>> hole(h+1);
        int tmp;
        bool flag;
        for(int i=1;i<=h;i++)
            std::cin >> hole[i].first >> hole[i].second;
        for(int i=1;i<=m;i++){
            path[0].push_back(i);
            path[i].push_back(0);
            cf[0][i].capacity=1;
            std::cin >> x1 >> y1;
            for(int j=1;j<hole.size();j++){
                tmp=0;
                flag=false;
                for(int l=0;l<map.size();l++){
                    if(hole[j]==map[l].end)
                        flag=true;
                    tmp+=line_cross({{x1,y1},hole[j]},map[l]);
                }
                if(tmp==1 || (flag&&tmp==2)){
                    path[i].push_back(j+m);
                    path[j+m].push_back(i);
                    cf[i][j+m].capacity=1;
                }
            }
        }
        for(int i=1;i<=hole.size();i++){
            path[i+m].push_back(h+m+1);
            path[h+m+1].push_back(i+m);
            cf[i+m][h+m+1].capacity=k;
        }
    };
    int line_cross(line a,line b){
        int s1 = CCW(a.start,a.end,b.start)*CCW(a.start,a.end,b.end);
        int s2 = CCW(b.start,b.end,a.start)*CCW(b.start,b.end,a.end);
        if(s1==0&&s2==0){
            if(a.start>a.end)
                swap(a.start,a.end);            
            if(b.start>b.end)
                swap(b.start,b.end);
            if(b.start<=a.end && a.start<=b.end)
                return 1;
            else 
                return 0;
        }
        else if(s1<=0 &&s2<=0)
            return 1;
        else
            return 0;
    }
    void edmond_karp(int sorce,int sink){
        int cur,next;
        int result=0;
        while(1){
            fill(prev.begin(),prev.end(),-1);
            queue<int> q;    
            q.push(sorce);
            while(!q.empty()&& prev[sink]==-1){
                cur=q.front();
                q.pop();
                for(int i=0;i<path[cur].size();i++){
                    next=path[cur][i];
                    if(cf[cur][next].capacity-cf[cur][next].flow>0 && prev[next]==-1){
                        prev[next]=cur;
                        q.push(next);
                        if(next==sink)
                            break;
                    }
                }
            }
            if(prev[sink]==-1)
                break;
            int flow =INF;
            for(int i=sink ;i!=sorce ;i=prev[i])
                flow=min(flow,cf[prev[i]][i].capacity-cf[prev[i]][i].flow);
            for(int i=sink ;i!=sorce ;i=prev[i]){
                cf[prev[i]][i].flow+=flow;
                cf[i][prev[i]].flow-=flow;
            }
            result+=flow;
        }
        if(result==m)
            std::cout << "Possible\n";
        else
            std::cout << "Impossible\n";

    }
    void find_sol(){
        edmond_karp(0,h+m+1);
    }
};
int main(){
    Tom_Jarry tj;
    tj.find_sol();
    return 0;
}