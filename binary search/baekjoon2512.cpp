#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct compare{
    bool operator()(int& a,int& b){
        return a>b;
    }
};
class budget{
private:
    priority_queue<int,vector<int>,compare> pq;
    int N,bud;
public:
    budget(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            pq.push(tmp);
        }
        std::cin >> bud;
    }
    void find_sol(){
        int sol=0;
        int cur,last=0,tmp;
        while(!pq.empty()){
            cur=pq.top();
            pq.pop();
            tmp=N*(cur-last);
            if(bud>=tmp){
                bud-=tmp;
                last=cur;
                sol=last;
                --N;
            }
            else{
                sol+=bud/N;
                break;
            }
        }
        std::cout << sol;
    }
};
int main(){
    budget bg;
    bg.find_sol();
    return 0;
}