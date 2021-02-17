#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define SIZE 30001
using namespace std;
struct _node{
    bool start;
    int x;
    int y1,y2;
};
bool cmp_node(_node& a,_node& b){
    return a.x<b.x;  
};
class mars_map{
private:
    vector<_node> point;
    vector<int> Y_stree;
    vector<int> Ylength;
    int N;
    int size;
public:
    mars_map(){
        std::cin >> N;
        set_val();
        size=1<<(int)ceil(log2(SIZE));
        Y_stree.resize(size*2,0);
        Ylength.resize(size*2,0);
    }
    void set_val(){
        int x1,y1,x2,y2;
        for(int i=0;i<N;i++){
            std::cin >> x1>>y1>>x2>>y2;
            point.push_back({true,x1,y1,y2});
            point.push_back({false,x2,y1,y2});
        }
        sort(point.begin(),point.end(),cmp_node);
    }
    void update(int node,int start,int end,int left,int right,int dif){
        if(right<start||end<left)
            return ;
        if(left<=start && end<=right){
            Y_stree[node]+=dif;
        }
        else{
            int mid=(start+end)/2;
            update(node*2,start,mid,left,right,dif);
            update(node*2+1,mid+1,end,left,right,dif);
        }
        
        if(Y_stree[node]){
            Ylength[node]=end-start+1;
        }
        else{
            if(start==end)
                Ylength[node]=0;
            else
                Ylength[node]=Ylength[node*2]+Ylength[node*2+1];
        }
    }
    void find_area(){
        int sol=0;
        int dx=0,dif;
        for(int i=0;i<point.size();i++){
            if(i>0){
                dx=point[i].x-point[i-1].x;
                sol+=Ylength[1]*dx;
            }
            dif=point[i].start?1:-1;
            update(1,1,size,point[i].y1+1,point[i].y2,dif);
        }
        std::cout <<sol ;
    }
};
int main(){
    mars_map mm;
    mm.find_area();

    return 0;
}