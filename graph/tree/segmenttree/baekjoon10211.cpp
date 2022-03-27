#include <iostream>
#include <vector>
#include <cmath>
#define INF 1000000000
using namespace std;
class interval_sum{
public:
    vector<int> stree;
    int N;
    int size;
public:
    interval_sum(){
        std::cin >> N;
        size=1<<(int)ceil(log2(N));
        stree.resize(size*2,0);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++){
            std::cin >> stree[size+i];
        }
        for(int i=size-1;i>0;i--){
            stree[i]=stree[i*2]+stree[i*2+1];
        }
    }
    int find_sum(int node,int start,int end,int left,int right){
        if(right<start||end<left)
            return 0;
        if(left<=start && end<=right)
            return stree[node];
        int mid=(start+end)/2;
        return find_sum(node*2,start,mid,left,right)+find_sum(node*2+1,mid+1,end,left,right);
    }
    void find_sol(){
        int sol=-INF;
        for(int i=1;i<=N;i++)
            for(int j=i;j<=N;j++)
                sol=max(sol,find_sum(1,1,size,i,j));   
        std::cout << sol << '\n';
    }

};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        interval_sum is;
        is.find_sol();
    }

    return 0;
}