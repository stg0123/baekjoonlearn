#include <iostream>
#include <queue>
using namespace std;
class circler_q{
private:
    queue<int> q;
    int N,M;
public:
    circler_q(){
        std::cin >> N >> M; 
        set_val();
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            q.push(i);
    }
    void move(){
        q.push(q.front());
        q.pop();
    }
    void yosepus(){
        std::cout << '<';
        while(!q.empty()){
            for(int i=0;i<M-1;i++)
                move();
            std::cout << q.front();
            q.pop();
            if(q.empty())
                break;
            std::cout << ", ";

        }
        std::cout << '>';
    }  
};
int main(){
    circler_q cq;
    cq.yosepus();

    return 0;
}