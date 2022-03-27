#include <iostream>
#include <queue>
using namespace std;
class card{
private:
    queue<int> q;
    int N;
public:
    card(){
        std::cin >> N;
        for(int i=1;i<=N;i++)
            q.push(i);
    }
    void find_sol(){
        while(q.size()>1){
            std::cout << q.front()<<' ';
            q.pop();
            q.push(q.front());
            q.pop();
        }
        std::cout << q.front()<<'\n';
    }


};
int main(){
    card cd;
    cd.find_sol();
    return 0;
}