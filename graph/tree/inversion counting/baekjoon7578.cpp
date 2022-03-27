#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;
typedef long long ll;
class factory{
private:
    unordered_map<int,int> m;
    vector<int> val;
    vector<int> stree;
    int N;
    int size;
public:
    factory(){
        std::cin >> N;
        size = 1<< (int)ceil(log2(N));
        stree.resize(size*2,0);
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            val.push_back(tmp);
        }
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            m[tmp]=i;
        }
    }
    int intervalsum(int node,int start,int end,int left,int right){
        if(right<start || end<left)
            return 0;
        if(left<=start&&end<=right)
            return stree[node];
        int mid=(start+end)/2;
        return intervalsum(node*2,start,mid,left,right)+intervalsum(node*2+1,mid+1,end,left,right);        
    }
    void update(int index){
        stree[index]=1;
        while(index>1){
            index/=2;
            stree[index]=stree[index*2]+stree[index*2+1];
        }
    }

    void find_sol(){
        ll sol=0;
        for(int i=0;i<N;i++){
            sol +=intervalsum(1,1,size,m[val[i]]+1,size);
            update(size+m[val[i]]);
        }
        std::cout << sol;
    }
};
int main(){
    factory fa;
    fa.find_sol();

    return 0;
}