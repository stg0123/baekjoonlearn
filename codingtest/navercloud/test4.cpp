#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct _node{
    int val=0;
    int lazy=0;
};
class test4{
private:
    vector<_node> stree;
    vector<int> sol;
    int size;
public:
    test4(){
        size = 1<<(int)ceil(log2(86400));
        stree.resize(size*2);
    }
    void find_max(int node,int start,int end){
        propagation(node,start,end);
        if(start>end)
            return ;
        if(stree[node].val==stree[1].val){
            if(start==end)
                sol.push_back(start-1);
            else{
                int mid =(start+end)/2;
                find_max(node*2,start,mid);
                find_max(node*2+1,mid+1,end);
            }
        }
        return ;
        
    }
    void update(int node,int start,int end,int left,int right){
        propagation(node,start,end);
        if(right<start || end<left)
            return ;
        if(left<=start && end<=right){
            stree[node].val+=1;
            if(start!=end){
                stree[node*2].lazy+=1;
                stree[node*2+1].lazy+=1;
            }
            return ;
        }
        int mid =(start+end)/2;
        update(node*2,start,mid,left,right);
        update(node*2+1,mid+1,end,left,right);
        stree[node].val=max(stree[node*2].val,stree[node*2+1].val);
    }
    void propagation(int node,int start,int end){
        if(stree[node].lazy){
            stree[node].val+=stree[node].lazy;
            if(start!=end){
                stree[node*2].lazy+=stree[node].lazy;
                stree[node*2+1].lazy+=stree[node].lazy;
            }
            stree[node].lazy=0;
        }
    }
    vector<int> find_sol(vector<vector<int>> info){
        for(int i=0;i<info.size();i++){
            update(1,1,size,info[i][0]+1,info[i][1]+1);
        }
        find_max(1,1,size);
        return sol;
    }

};
int main(){
    test4 t4;
    vector<vector<int>> info = {{1,5},{3,5},{7,8}};
    vector<int> sol = t4.find_sol(info);
    for(int i : sol)
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}