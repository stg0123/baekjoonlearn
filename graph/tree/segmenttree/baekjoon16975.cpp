#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
class arr_query21{
private:
    vector<ll> stree;
    int N;
    int size;
public:
    arr_query21(){
        std::cin >>N;
        size=1<<(int)ceil(log2(N));
        stree.resize(size*2,0);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> stree[size+i];
    }
    void query1(int node,int start,int end,int left,int right,ll val){
        if(right<start || end<left)
            return ;
        if(left<=start && end<=right){
            stree[node]+=val;
            return ;
        }
        int mid = (start+end)/2;
        query1(node*2,start,mid,left,right,val);
        query1(node*2+1,mid+1,end,left,right,val);
    }
    ll query2(int index){
        ll sol=0;
        while(index>0){
            sol+=stree[index];
            index/=2;
        }
        return sol;
    }
    void start_query(){
        int n,a,b,c;
        ll d;
        std::cin >> n;
        for(int i=0;i<n;i++){
            std::cin >> a;
            if(a==1){
                std::cin >> b >> c >> d;
                query1(1,1,size,b,c,d);
            }
            else if(a==2){
                std::cin >> b;
                std::cout << query2(b+size-1)<<'\n';
            }
        }
    }

};
int main(){
    arr_query21 aq;
    aq.start_query();
    return 0;
}