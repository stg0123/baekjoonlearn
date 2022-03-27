#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class yosepus{
private:
    vector<int> stree;
    int N,M;
    int size;
public:
    yosepus(){
        std::cin >> N>>M;
        size=1<<(int)ceil(log2(N));
        stree.resize(size*2,0);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            stree[i+size]=1;
        for(int i=size-1;i>0;i--)
            stree[i]=stree[i*2]+stree[i*2+1];
    }
    void update(int index,int dif){
        while(index>0){
            stree[index]+=dif;
            index/=2;
        }
    }
    int find(int node,int start,int end,int k){
        if(start==end)
            return end;
        int mid=(start+end)/2;
        if(stree[node*2]>=k)
            return find(node*2,start,mid,k);
        return find(node*2+1,mid+1,end,k-stree[node*2]);
    }
    void start_yosepus(){
        int index=1,leave=N,tmp;
        std::cout << '<';
        while(leave>0){
            index+=M-1;
            index%=leave;
            if(index==0)
                index=leave;
            tmp=find(1,1,size,index);
            std::cout << tmp;
            update(tmp+size-1,-1);
            leave--;
            if(leave==0)
                break;
            std::cout << ", "; 
        }
        std::cout << '>';
    }

};
int main(){
    yosepus yo;
    yo.start_yosepus();

    return 0;
}