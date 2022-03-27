#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class drunkcode{
private:
    vector<int> stree;
    int size;
    int N,K;
public:
    drunkcode(int n,int k):N(n),K(k){
        size = 1 <<(int)ceil(log2(N));
        stree.resize(size*2);
        set_val();
    }
    void set_val(){
        int a;
        for(int i=0;i<N;i++){
            std::cin >>a;
            if(a>0)
                stree[size+i]=1;
            else if(a<0)
                stree[size+i]=-1;
            else
                stree[size+i]=0;
        }
        for(int i=size-1;i!=0;i--)
            stree[i]=stree[i*2]*stree[i*2+1];
    }
    int interval_mul(int node,int start,int end,int left,int right){
        if(right<start || end<left)
            return 1;
        if(left<=start && end<=right)
            return stree[node];
        int mid =(start+end)/2;
        return interval_mul(node*2,start,mid,left,right)*interval_mul(node*2+1,mid+1,end,left,right);
    }
    void update(int index,int change){
        if(change>0)
            stree[index]=1;
        else if (change<0)
            stree[index]=-1;
        else
            stree[index]=0;
        while(index>1){
            index/=2;
            stree[index]=stree[index*2]*stree[index*2+1];
        }
    }
    void start_query(){
        char ch;
        int a,b,tmp;
        for(int i=0;i<K;i++){
            std::cin >> ch >> a >> b;
            if(ch == 'C')
                update(size+a-1,b);
            else{
                tmp = interval_mul(1,1,size,a,b);
                if(tmp>0)
                    std::cout << '+';
                else if(tmp<0)
                    std::cout << '-';
                else 
                    std::cout << 0;
            }
        }
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    while(1){
        std::cin >> n >> k;
        if(cin.eof())
            break;
        drunkcode dk(n,k);
        dk.start_query();
        std::cout << '\n';
    }
    return 0;
}