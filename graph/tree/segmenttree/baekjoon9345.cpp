#include <iostream>
#include <vector>
#include <cmath>
#define INF 1000000000
using namespace std;
typedef long long ll;
class DVDs{
private:
    vector<pair<int,int>> stree;
    int N;
    int size;
public:
    DVDs(int n):N(n){
        size=1<<(int)ceil(log2(N));
        stree.resize(size*2,{0,0});
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++){
            stree[i+size]={i,i};
        }
        for(int i=size-1;i>0;i--){
            stree[i].first=min(stree[i*2].first,stree[i*2+1].first);
            stree[i].second=max(stree[i*2].second,stree[i*2+1].second);
        }
    }
    pair<int,int> find_min_max(int a,int b){
        return min_max(1,1,size,a+1,b+1);
    }
    pair<int,int> min_max(int node,int start,int end,int left,int right){
        if(right<start || end<left)
            return {INF,0};
        if(left<=start && end<=right)
            return stree[node];
        int mid=(start+end)/2;
        pair<int,int> tmp1 =min_max(node*2,start,mid,left,right);
        pair<int,int> tmp2 =min_max(node*2+1,mid+1,end,left,right);
        return {min(tmp1.first,tmp2.first),max(tmp1.second,tmp2.second)};
    }
    void update(int index){
        while(index>1){
            index/=2;
            stree[index]={min(stree[index*2].first,stree[index*2+1].first),max(stree[index*2].second,stree[index*2+1].second)};
        }
    }
    void swap(int a,int b){
        pair<int,int> tmp =stree[size+b];
        stree[size+b]=stree[size+a];
        update(size+b);
        stree[size+a]=tmp;
        update(size+a);
    }

};
int main(){
    int n,a,b;
    int op1,op2,op3;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >>a >> b;
        DVDs check(a);
        DVDs dvd(a);
        for(int j=0;j<b;j++){
            std::cin >> op1 >> op2 >> op3;
            if(op1==0)
                dvd.swap(op2,op3);
            else if(op1==1){
                if(dvd.find_min_max(op2,op3)==check.find_min_max(op2,op3))
                    std::cout << "YES\n";
                else
                    std::cout << "NO\n";
            }
        }
    }

    return 0;
}