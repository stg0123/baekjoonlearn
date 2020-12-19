#include <iostream>
#include <vector>
#include <queue>

using namespace std;
template<typename T>
struct compare{
    bool operator()(T a,T b){
        if(abs(a)==abs(b))
            return a>b;
        return abs(a)>abs(b);
    }
};

class my_heap{
private:
    priority_queue<int, vector<int>, compare<int>> pq;
    int N;
public:
    my_heap(int n):N(n){};
    
    void input(){
        int a;
        for(int i=0;i<N;i++){
            std::cin >> a;
            if(a==0){
                if(pq.empty())
                    std::cout << 0<<'\n';
                else{
                    std::cout << pq.top()<<'\n';
                    pq.pop();
                }
            }
            else if(a!=0)
                pq.push(a);
                
        }
    };

};
int main(){
    int n;
    std::cin >> n;
    my_heap mh(n);
    mh.input();

    return 0;
}