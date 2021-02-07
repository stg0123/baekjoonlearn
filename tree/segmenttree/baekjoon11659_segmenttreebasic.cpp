#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
class seg_tree{
private:
    vector<ll> s_tree;
    vector<int> val;
    int N,M;
    int size;
public:
    seg_tree(){
        std::cin >> N >>M;
        val.resize(N+1,0);
        size=(1<<(int)ceil(log2(N)));
        s_tree.resize(size*2,0);
        set_val();
        make_stree(1,1,N);
    }
    void print_stree(){
        for(int i=0;i<val.size();i++)
            std::cout << val[i] << ' ';
        std::cout << '\n';
        std::cout << size << '\n';
        for(int i=0;i<s_tree.size();i++){
            std::cout << s_tree[i]<< ' ';
        }
        std::cout << '\n';

    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> val[i];
    }

    ll make_stree(int node,int start,int end){
        if(start==end){
            s_tree[node]=val[start];
            return s_tree[node];
        }
        int mid=(start+end)/2;
        s_tree[node]=make_stree(node*2,start,mid)+make_stree(node*2+1,mid+1,end);
        return s_tree[node];
    }
    ll sum(int node,int start,int end,int left,int right){
        if(left>end||right<start)
            return 0;
        if(left<=start&&end<=right)
            return s_tree[node];
        
        int mid = (start+end)/2;
        return sum(node*2,start,mid,left,right)+sum(node*2+1,mid+1,end,left,right);
    }
    void update(int node,int start,int end,int index,int diff){
        if(index<start || end<index)
            return ;
        s_tree[node]+=diff;
        if(start==end)
            return ;
        int mid =(start+end)/2;
        update(node*2,start,mid,index,diff);
        update(node*2+1,mid+1,end,index,diff);
        return ;
    }

    void find_sum(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a >> b;
            std::cout << sum(1,1,N,a,b)<<'\n';
        }
    }
};
int main(){
    seg_tree stree;
    stree.find_sum();

    return 0;
}