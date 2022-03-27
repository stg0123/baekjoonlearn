#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 100002
using namespace std;
typedef long long ll;
struct _node{
    int val=0;
    _node* left,* right;

    _node* insert(int left,int right,int dst,int value){
        if(dst<left || right<dst)
            return this;
        _node* leaf = new _node;
        if(left==right){
            leaf->val=this->val+value;
            return leaf;
        }
        int mid =(left+right)/2;
        leaf->left = this->left->insert(left,mid,dst,value);
        leaf->right = this->right->insert(mid+1,right,dst,value);
        leaf->val= leaf->left->val +leaf->right->val;
        return leaf;
    }    

};
class egg{
private:
    vector<_node*> head;
    vector<vector<int>> val;
    int N,M;
public:
    egg(){
        std::cin >>N >> M;
        head.resize(SIZE);
        head[0]=new _node;
        head[0]->left =head[0]->right = head[0];
        head[0]->val =0;
        val.resize(SIZE);
        set_val();
    }
    void set_val(){
        int x,y;
        for(int i=1;i<=N;i++){
            std::cin >> x >> y;
            x++,y++;
            val[x].push_back(y);
        }
        for(int i=1;i<SIZE;i++){
            head[i] = head[i-1];
            for(int j=0;j<val[i].size();j++){
                head[i] = head[i]->insert(1,SIZE,val[i][j],1);
            }
        }
    }
    ll qry(_node* now,int start,int end,int left,int right){
        if(right<start||end<left)
            return 0;
        if (left <= start && end<=right)
            return now->val;
        int mid=(start+end)/2;
        return qry(now->left,start,mid,left,right)+qry(now->right,mid+1,end,left,right);   
    }
    void find_sol(){
        ll sol =0;
        int left,right,bottom,top;
        for(int i=0;i<M;i++){
            std::cin >> left >>right >>bottom >> top ;
            left++,right++,bottom++,top++;
            sol+=qry(head[right],1,SIZE,bottom,top);
            sol-=qry(head[left-1],1,SIZE,bottom,top);
        }
        std::cout << sol<<'\n';
    }

};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        egg eg;
        eg.find_sol();
    }
    return 0;
}