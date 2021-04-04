#include <iostream>
#include <vector>
#include <cmath>
#define INF 1000000000000000000
using namespace std;
typedef long long ll;
class waterpark{
private:
    vector<ll> map;
    vector<ll> stree;
    int N,D;
    int size;
public:
    waterpark(){
        std::cin >> N >> D;
        map.resize(N+1,0);
        size = 1<<(int)ceil(log2(N));
        stree.resize(size*2,0);
        set_val();
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> map[i];
    }
    void start_dp(){
        for(int i=1;i<=N;i++)
            DP(i);
        std::cout << interval_max(1,1,size,1,N);
    }
    void DP(int n){
        int tmp=n-D;
        if(tmp<=0)
            tmp=1;
        update(size+n-1,interval_max(1,1,size,tmp,n)+map[n]);
    }
    ll interval_max(int node,int start,int end,int left,int right){
        if(right<start || end < left)
            return -INF;
        if(left<=start && end <= right)
            return stree[node];
        int mid=(start+end)/2;
        return max(interval_max(node*2,start,mid,left,right),interval_max(node*2+1,mid+1,end,left,right));
    }
    void update(int index,ll val){
        stree[index]=val;
        while(index>1){
            index/=2;
            stree[index]=max(stree[index*2],stree[index*2+1]);
        }
    }
};
int main(){
    waterpark wp;
    wp.start_dp();
    return 0;
}