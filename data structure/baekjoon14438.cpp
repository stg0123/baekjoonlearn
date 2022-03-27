#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int INF =1000000000;
class query17{
private:
    vector<int> stree;
    int size;
    int N;
public:
    query17(){
        std::cin >>N;
        size = 1<<(int)ceil(log2(N));
        stree.resize(size*2);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >>stree[size+i];
        for(int i=size-1;i!=0;i--)
            stree[i]=min(stree[i*2],stree[i*2+1]);
    }
    int interval_min(int node,int start,int end,int left,int right){
        if(right<start || end<left)
            return INF;
        if(left<=start && end<=right)
            return stree[node];
        int mid =(start+end)/2;
        return min(interval_min(node*2,start,mid,left,right),interval_min(node*2+1,mid+1,end,left,right));
    }
    void update(int index,int change){
        stree[index]=change;
        while(index>1){
            index/=2;
            stree[index]=min(stree[index*2],stree[index*2+1]);
        }
    }
    void start_query(){
        int M;
        std::cin >> M;
        int a,b,c;
        for(int i=0;i<M;i++){
            std::cin >> a >> b >> c;
            if(a==1)
                update(size+b-1,c);
            else
                std::cout <<interval_min(1,1,size,b,c)<<'\n';
        }
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    query17 q17;
    q17.start_query();
    return 0;
}