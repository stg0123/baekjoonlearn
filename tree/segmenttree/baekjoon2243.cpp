#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class candy{
private:
    vector<int> stree;
    int N;
    int size;
public:
    candy(){
        std::cin >> N;
        size=1<<(int)ceil(log2(1000000));
        stree.resize(size*2,0);
    }
    int find_idx(int node,int start,int end,int k){
        if(start==end)
            return node-size+1;
        int mid=(start+end)/2;
        if(stree[node*2]<k)
            return find_idx(node*2+1,mid+1,end,k-stree[node*2]);
        else
            return find_idx(node*2,start,mid,k);
    }
    void update(int index,int diff){
        while(index>0){
            stree[index]+=diff;
            index/=2;
        }
    }
    void start_query(){
        int a,b,c;
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >> a;
            if(a==1){
                std::cin >> b;
                tmp =find_idx(1,1,size,b);
                std::cout << tmp <<'\n';
                update(size+tmp-1,-1);
            }
            else{
                std::cin >> b >>c;
                update(size+b-1,c);
            }
        }

    }

};
int main(){
    candy ca;
    ca.start_query();

    return 0;
}