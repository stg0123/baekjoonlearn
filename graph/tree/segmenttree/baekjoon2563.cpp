#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct _node{
    bool start;
    int x;
    int y1,y2;
};
bool compare_node(_node& a,_node& b){
    return a.x<b.x;
};
class color_paper{
private:
    vector<_node> val;
    vector<int> stree;
    vector<int> length;
    int N;
    int size;
public:
    color_paper(){
        std::cin >> N;
        size=1<<(int)ceil(log2(100));
        stree.resize(size*2,0);
        length.resize(size*2,0);
        set_val();
    }
    void set_val(){
        int x,y;
        for(int i=0;i<N;i++){
            std::cin >> x>> y;
            val.push_back({true,x,y,y+10});
            val.push_back({false,x+10,y,y+10});
        }
        sort(val.begin(),val.end(),compare_node);      
    }
    void update(int node,int start,int end,int left,int right,int dif){
        if(right<start||end<left)
            return ;
        if(left<=start&&end<=right)
            stree[node]+=dif;
        else{
            int mid=(start+end)/2;
            update(node*2,start,mid,left,right,dif);
            update(node*2+1,mid+1,end,left,right,dif);
        }
        if(stree[node])
            length[node]=end-start+1;
        else{
            if(start==end)
                length[node]=0;
            else
                length[node]=length[node*2]+length[node*2+1];
        }
    }
    void find_area(){
        int sol=0;
        int dx=0,dif;
        for(int i=0;i<val.size();i++){
            if(i>0){
                dx=val[i].x-val[i-1].x;
                sol += length[1]*dx;
            }
            dif=val[i].start ? 1:-1;
            update(1,1,size,val[i].y1+1,val[i].y2,dif);
        }
        std::cout << sol <<'\n';
    }

};
int main(){
    color_paper cp;
    cp.find_area();
    return 0;
}