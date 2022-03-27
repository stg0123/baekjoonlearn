#include <iostream>
#include <vector>
#include <cmath>
#define INF 1000000001
using namespace std;
class interval_min_max{
private:
    vector<pair<int,int>> s_tree;
    vector<int> val;
    int N,M;
    int size;
public:
    interval_min_max(){
        std::cin >> N >> M;
        size=1<<(int)ceil(log2(N));
        s_tree.resize(size*2,{0,0});
        val.resize(N+1,0);
        set_val();
        make_stree(1,1,N);
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> val[i];
    }
    pair<int,int> make_stree(int node,int start,int end){
        if(start==end)
            return s_tree[node]={val[start],val[end]};
        int mid=(start+end)/2;
        pair<int,int> tmp1=make_stree(node*2,start,mid);
        pair<int,int> tmp2=make_stree(node*2+1,mid+1,end);
        s_tree[node].first=min(tmp1.first,tmp2.first);
        s_tree[node].second=max(tmp1.second,tmp2.second);
        return s_tree[node];
    }
    pair<int,int> find_min_max(int node,int start,int end,int left,int right){
        if(right<start || end<left)
            return {INF,0};
        if(left<=start && end<=right)
            return s_tree[node];
        int mid =(start+end)/2;
        pair<int,int> tmp1 =find_min_max(node*2,start,mid,left,right);
        pair<int,int> tmp2 =find_min_max(node*2+1,mid+1,end,left,right);
        return {min(tmp1.first,tmp2.first),max(tmp1.second,tmp2.second)};
    }
    void find_start(){
        int a,b;
        pair<int,int> tmp;
        for(int i=0;i<M;i++){
            std::cin >>a >> b;
            tmp=find_min_max(1,1,N,a,b);
            std::cout << tmp.first << ' '<<tmp.second << '\n';
        }

    }

};
int main(){
    interval_min_max imm;
    imm.find_start();

    return 0;
}