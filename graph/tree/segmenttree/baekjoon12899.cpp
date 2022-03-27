#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class data_structure{
private:
    vector<int> stree;
    int N;
    int size;
public:
    data_structure(){
        N=2000000;
        size=1<<(int)ceil(log2(N));
        stree.resize(size*2,0);
    }
    void update(int index,int dif){
        while(index>0){
            stree[index]+=dif;
            index/=2;
        }
    }
    int find(int node,int start,int end,int k){
        if(start==end)
            return start;
        int mid=(start+end)/2;
        if(stree[node*2]>=k)
            return find(node*2,start,mid,k);
        return find(node*2+1,mid+1,end,k-stree[node*2]);
    }
    void oper(){
        int n,a,b,tmp;
        std::cin >> n;
        for(int i=0;i<n;i++){
            std::cin >> a >> b;
            if(a==1)
                update(b+size-1,1);
            else if(a==2){
                tmp = find(1,1,size,b);
                std::cout << tmp << '\n';
                update(tmp+size-1,-1);
            }
        }
    }
};
int main(){
    data_structure ds;
    ds.oper();

    return 0;
}