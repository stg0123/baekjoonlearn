#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
int powmod=1e9+7;
class interval_mul{
private:
    vector<ll> s_tree;
    vector<ll> val;
    int N,M,K;
    int size;
public:
    interval_mul(){
        std::cin >> N >> M >> K;
        val.resize(N+1,0);
        size =1<<(int)ceil(log2(N));
        s_tree.resize(size*2,0);
        set_val();
        make_stree(1,1,N);
    }
    void print_stree(){
        for(int i=0;i<s_tree.size();i++)
            std::cout << s_tree[i] << ' ';
        std::cout << '\n';
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> val[i];
    }
    ll make_stree(int node,int start,int end){
        if(start==end)
            return s_tree[node]=val[start];
        int mid= (start+end)/2;
        return s_tree[node]=(make_stree(node*2,start,mid)*make_stree(node*2+1,mid+1,end))%powmod;
    }
    ll findmul(int node,int start,int end,int left,int right){
        if(right<start || end<left)
            return 1;
        if(left<=start&&end<=right)
            return s_tree[node];
        int mid=(start+end)/2;
        return (findmul(node*2,start,mid,left,right)*findmul(node*2+1,mid+1,end,left,right))%powmod;
    }
    ll update(int node,int start,int end,int index){
        if(index<start||end<index)
            return s_tree[node];
        if(start==end)
            return s_tree[node]=val[index];
        int mid=(start+end)/2;
        s_tree[node]=(update(node*2,start,mid,index)*update(node*2+1,mid+1,end,index))%powmod;
        return s_tree[node];
    }
    void oper(){
        int a,b,c;
        for(int i=0;i<M+K;i++){
            std::cin >> a >> b >> c;
            if(a==1){
                val[b]=c;
                update(1,1,N,b);
            }
            else
                std::cout << findmul(1,1,N,b,c)<<'\n';
        }
    }
};
int main(){
    interval_mul im;
    im.oper();

    return 0;
}