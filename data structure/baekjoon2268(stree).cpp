#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
class stree_basic{
private:
    vector<ll> stree;
    int size;
public:
    stree_basic(){
        int N;
        std::cin >>N;
        size = 1 << (int)ceil(log2(N));
        stree.resize(size*2,0);
    }
    ll interval_sum(int node,int start,int end,int left,int right){
        if(right<start || end<left)
            return 0;
        if(left<=start && end<=right)
            return stree[node];
        int mid = (start+end)/2;
        return interval_sum(node*2,start,mid,left,right)+interval_sum(node*2+1,mid+1,end,left,right);
    }
    void update(int index,int change){
        stree[index]=change;
        while(index>1){
            index/=2;
            stree[index]=stree[index*2]+stree[index*2+1];
        }
    }
    void start_query(){
        int M;
        std::cin >>M;
        int a,b,c;
        for(int i=0;i<M;i++){
            std::cin >>a >> b >> c;
            if(a)
                update(size+b-1,c);
            else{
                if(b>c)
                    swap(b,c);
                std::cout << interval_sum(1,1,size,b,c) << '\n';
            }
        }
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    stree_basic sb;
    sb.start_query();

    return 0;
}