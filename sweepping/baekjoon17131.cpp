#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
int powmod=1e9+7;
bool compare_star(pair<int,int>& a,pair<int,int>& b){
    return (a.second==b.second) ? a.first<b.first : a.second<b.second;
};
class soongsilzzang{
private:
    vector<pair<int,int>> star;
    vector<int> Xval;
    vector<int> stree;
    int N;
    int size;
public:
    soongsilzzang(){
        std::cin >> N;
        size=1<<(int)ceil(log2(N));
        stree.resize(size*2,0);
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<N;i++){
            std::cin >> a >>b;
            star.push_back({a,b});
            Xval.push_back(a);
            stree[size+i]=1;
        }
        sort(star.begin(),star.end(),compare_star);
        sort(Xval.begin(),Xval.end());
        for(int i=size-1;i>0;i--)
            stree[i]=stree[i*2]+stree[i*2+1];
    }
    void print_stree(){
        for(int i=0;i<N;i++)
            std::cout << stree[size+i] << ' ';
        std::cout << '\n';
    }
    ll interval_sum(int node,int start,int end,int left,int right){
        if(right<start || end <left)
            return 0;
        if(left<=start && end <=right)
            return stree[node];
        int mid=(start+end)/2;
        return interval_sum(node*2,start,mid,left,right)+interval_sum(node*2+1,mid+1,end,left,right);
    }
    void update(int index){
        while(index>0){
            stree[index]--;
            index/=2;
        }
    }
    void find_sol(){
        int tmp1,tmp2,index1,index2;
        ll sol=0;
        for(int i=0;i<star.size();){
            tmp1=i;
            tmp2=star[i].second;
            while(i<star.size()){
                if(tmp2==star[i].second){
                    index1=upper_bound(Xval.begin(),Xval.end(),star[i].first)-Xval.begin()-1;
                    update(index1+size);
                    i++;
                }
                else
                    break;
            }
            for(int j=tmp1;j<i;j++){
                index1=lower_bound(Xval.begin(),Xval.end(),star[j].first)-Xval.begin();
                index2=upper_bound(Xval.begin(),Xval.end(),star[j].first)-Xval.begin()+1;
                sol +=(interval_sum(1,1,size,1,index1)*interval_sum(1,1,size,index2,size))%powmod;
                sol %=powmod;

            }
        }
        std::cout << sol << '\n';
    }

};
int main(){
    soongsilzzang ssu;
    ssu.find_sol();
    return 0;
}