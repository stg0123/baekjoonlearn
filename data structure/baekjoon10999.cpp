#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
struct _node{
    ll val=0,lazy=0;
};
class lazy_propagation{
private:
    vector<_node> stree;
    int size;
    int N,M;
public:
    lazy_propagation(){
        int a,b;
        std::cin >> N >> a >> b;
        M = a+b;
        size = 1<<(int)ceil(log2(N));
        stree.resize(size*2);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> stree[size+i].val;
        for(int i=size-1;i!=0;i--)
            stree[i].val=stree[i*2].val+stree[i*2+1].val;
    }
    ll interval_sum(int node,int start,int end,int left,int right){
        propagation(node,start,end);
        if(right<start || end<left)
            return 0;
        if(left<=start && end<=right)
            return stree[node].val;
        int mid=(start+end)/2;
        return interval_sum(node*2,start,mid,left,right)+interval_sum(node*2+1,mid+1,end,left,right);
    }
    void update(int node,int start,int end,int left,int right,ll diff){
        propagation(node,start,end);
        if(right<start || end<left)
            return ;
        if(left<=start && end<=right){
            stree[node].val+=(end-start+1)*diff;
            if(start!=end){
                stree[node*2].lazy+=diff;
                stree[node*2+1].lazy+=diff;
            }
            return ;
        }
        int mid = (start+end)/2;
        update(node*2,start,mid,left,right,diff);
        update(node*2+1,mid+1,end,left,right,diff);
        stree[node].val=stree[node*2].val+stree[node*2+1].val;
    }
    void propagation(int node,int start,int end){
        if(stree[node].lazy){
            stree[node].val+=(end-start+1)*stree[node].lazy;
            if(start!=end){
                stree[node*2].lazy+=stree[node].lazy;
                stree[node*2+1].lazy+=stree[node].lazy;
            }
            stree[node].lazy=0;
        }
    }
    void start_query(){
        int a,b,c;
        ll d;
        for(int i=0;i<M;i++){
            std::cin >>a;
            if(a==1){
                std::cin >> b >> c >> d;
                update(1,1,size,b,c,d);
            }
            else{
                std::cin >> b >> c;
                std::cout << interval_sum(1,1,size,b,c)<<'\n';
            }
        }
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    lazy_propagation lp;
    lp.start_query();


    return 0;
}