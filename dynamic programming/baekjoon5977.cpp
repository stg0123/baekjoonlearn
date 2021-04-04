#include <iostream>
#include <vector>
#include <cmath>
#define INF 1000000000000000000
using namespace std;
typedef long long ll;
class Mowing{
private:
    vector<ll> stree;
    vector<ll> dp;
    vector<ll> prefix_sum;
    int N,D;
    int size;
public:
    Mowing(){
        std::cin >> N >>D;
        size = 1<<(int)ceil(log2(N+1));
        stree.resize(size*2,0);
        prefix_sum.resize(N+2,0);
        set_val();
    }
    ll interval_max(int node,int start,int end,int left,int right){
        if(right<start || end<left)
            return -INF;
        if(left<=start && end<=right)
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
    void set_val(){
        ll tmp;        
        for(int i=1;i<=N;i++){
            std::cin >> tmp;
            prefix_sum[i]=prefix_sum[i-1]+tmp;
        }
    }
    void start_dp(){
        for(int i=0;i<=N;i++)
            DP(i);
        
    }
    void DP(int n){
        ll sol;
        if(n-D<=0)
            sol=prefix_sum[n];
        else
            sol=interval_max(1,1,size,n-D,n)+prefix_sum[n];
        if(n==N)
            std::cout << sol << '\n';
        else 
            update(size+n,sol-prefix_sum[n+1]);
    }


};
int main(){
    Mowing mo;
    mo.start_dp();
    return 0;
}