#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
class coffee{
private:
    vector<ll> stree;
    int N,M;
    int size;
public:
    coffee(){
        std::cin >> N >> M;
        size = 1<<(int)ceil(log2(N));
        stree.resize(size*2,0);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> stree[size+i];
        
        for(int i=size-1;i>0;i--)
            stree[i]=stree[i*2]+stree[i*2+1];
        
    }
    ll interval_sum(int node,int start,int end,int left,int right){
        if(right<start || end <left)
            return 0;
        if(left<=start && end<=right)
            return stree[node];
        int mid=(start+end)/2;
        return interval_sum(node*2,start,mid,left,right)+interval_sum(node*2+1,mid+1,end,left,right);
    }
    void update(int index,ll change){
        stree[index]=change;
        while(index>1){
            index/=2;
            stree[index]=stree[index*2]+stree[index*2+1];
        }
    }
    void find_sol(){
        ll x,y,a,b;
        for(int i=0;i<M;i++){
            std::cin >> x >> y >> a >> b;
            if(x>y)
                std::cout << interval_sum(1,1,size,y,x) <<'\n';
            else
                std::cout << interval_sum(1,1,size,x,y) << '\n';
            update(size+a-1,b);
        }
    }
};
int main(){
    coffee cof;
    cof.find_sol();
    return 0;
}
