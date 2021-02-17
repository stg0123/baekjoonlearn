#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
struct _node{
    bool start;
    int x;
    int y1,y2;
};
bool compare_node(_node& a,_node& b){
    return a.x<b.x;
};
class rectangle{
private:
    vector<_node> point;
    vector<int> Yval;
    vector<int> stree;
    vector<ll> Ylength_tree;
    int N;
    int size;
public:
    rectangle(){
        std::cin >> N;
        set_val();
        size=1<<(int)ceil(log2(Yval.size()));
        stree.resize(size*2,0);
        Ylength_tree.resize(size*2,0);
    }
    void set_val(){
        int x1,x2,y1,y2;
        for(int i=0;i<N;i++){
            std::cin >> x1 >> x2 >> y1 >> y2;
            point.push_back({true,x1,y1,y2});
            point.push_back({false,x2,y1,y2});
            Yval.push_back(y1);
            Yval.push_back(y2);
        }
        sort(point.begin(),point.end(),compare_node);
        sort(Yval.begin(),Yval.end());
        Yval.erase(unique(Yval.begin(),Yval.end()),Yval.end());
    }
    void update(int node,int start,int end,int left,int right,int dif){
        if(right<start || end<left)
            return ;
        if(left<=start && end<=right){
            stree[node]+=dif;
        }
        else{
            int mid=(start+end)/2;
            update(node*2,start,mid,left,right,dif);
            update(node*2+1,mid+1,end,left,right,dif);
        }

        if(stree[node]){
            Ylength_tree[node]= (ll)Yval[end]-Yval[start-1];
        }
        else{
            if(start==end)
                Ylength_tree[node]=0;
            else
                Ylength_tree[node]=Ylength_tree[node*2]+Ylength_tree[node*2+1];
        }
    }
    void find_area(){
        ll sol =0;
        int dx=0,dif;
        int index1,index2;
        for(int i=0;i<point.size();i++){
            if(i>0){
                dx=point[i].x-point[i-1].x;
                sol+=Ylength_tree[1]*dx;
            }
            dif= point[i].start ? 1:-1;
            index1=lower_bound(Yval.begin(),Yval.end(),point[i].y1)-Yval.begin();
            index2=lower_bound(Yval.begin(),Yval.end(),point[i].y2)-Yval.begin();
            update(1,1,size,index1+1,index2,dif);
        }
        std::cout << sol;
    }


};
int main(){
    rectangle rg;
    rg.find_area();

    return 0;
}