#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
struct compare{
    bool operator()(ll& a,ll& b){
        return a>b;
    }
};
class basic_pq{
private: 
    priority_queue<ll,vector<ll>,compare> pq;
    int n,m;
public:
    basic_pq(){
        std::cin >> n >> m;
        set_val();
    }
    void set_val(){
        ll tmp;
        for(int i=0;i<n;i++){
            std::cin >> tmp ;
            pq.push(tmp);
        }
    }
    void find_sol(){
        ll a,b;
        for(int i=0;i<m;i++){
            a=pq.top();
            pq.pop();
            b=pq.top();
            pq.pop();
            pq.push(a+b);
            pq.push(a+b);
        }
        ll sol=0;
        while(!pq.empty()){
            sol+=pq.top();
            pq.pop();
        } 
        std::cout << sol << "\n";
    }


};
int main(){
    basic_pq bpq;
    bpq.find_sol();

    return 0;
}