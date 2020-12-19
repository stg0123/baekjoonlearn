#include <iostream>
#include <queue>
using namespace std;

class maxhip{
private:
    priority_queue<int> pq;
    int N;
public :
    maxhip(int n):N(n){

    };
    
    void input(){
        int a;
        for(int i=0;i<N;i++){
            std::cin >> a;
            if(a>0)
                pq.push(a);
            else if(a==0){
                if(pq.empty())
                    std::cout << 0<<'\n';
                else{
                    std::cout << pq.top()<<'\n';
                    pq.pop();
                }
            }
        }
    }
};
int main(){
    int n;
    std::cin >> n;
    maxhip mh(n);
    mh.input();    
    return 0;
}