#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
bool compare_island(pair<int,int>& a,pair<int,int>& b){
    return  (a.first==b.first) ? a.second>b.second:a.first<b.first;
};
bool compare_Y(int a,int b){
    return a>b;
};
class northwester{
private:
    vector<pair<int,int>> island;
    vector<int> Yval;
    vector<int> stree;
    int N;
    int size;
public:
    northwester(){
        std::cin >> N;
        size=1<<(int)ceil(log2(N));
        stree.resize(size*2,0);
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<N;i++){
            std::cin >> a >>b ;
            island.push_back({a,b});
            Yval.push_back(b);
        }
        sort(island.begin(),island.end(),compare_island);
        sort(Yval.begin(),Yval.end(),compare_Y);
    }
    int interval_sum(int node,int start,int end,int left,int right){
        if(right<start || end<left)
            return 0;
        if(left<=start && end <= right)
            return stree[node];
        int mid = (start+end)/2;
        return interval_sum(node*2,start,mid,left,right)+interval_sum(node*2+1,mid+1,end,left,right);
    }
    void update(int index){
        while(index>0){
            stree[index]++;
            index/=2;
        }
    }
    void find_line(){
        ll sol=0;
        int index;
        for(int i=0;i<island.size();i++){
            index=upper_bound(Yval.begin(),Yval.end(),island[i].second,compare_Y)-Yval.begin()-1;
            sol+=interval_sum(1,1,size,1,index+1);
            update(index+size);
        }
        std::cout << sol << '\n';
    }
};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        northwester nw;
        nw.find_line();
    }

    return 0;
}