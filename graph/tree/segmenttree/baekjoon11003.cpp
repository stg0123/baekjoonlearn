#include <iostream>
#include <vector>
#include <cmath>
#define INF 1000000001
using namespace std;

class find_min{
private:
    vector<int> stree;
    int N,M;
    int size;
    int idx=0;
public:
    find_min(){
        std::cin >> N >> M;
        size=1<<(int)ceil(log2(M));
        stree.resize(size*2,INF);
    }
    void update(int index,int N){
        stree[index]=N;
        while(index>1){
            index/=2;
            stree[index]=min(stree[index*2],stree[index*2+1]);
        }
    }
    void find_sol(){
        int val;
        for(int i=0;i<N;i++){
            std::cin >> val;
            update(size+idx,val);
            std::cout << stree[1]<< ' ';
            idx=(idx+1)%M;
        }
    }

};
int main(){
    find_min fm;
    fm.find_sol();
    return 0;
}