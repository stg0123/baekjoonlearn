#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class card{
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int N;
public:
    card(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            pq.push(tmp);
        }
    }
    void find_sol(){
        if(N==1){
            std::cout << 0<<'\n';
            return ;
        }
        int sol=0,tmp;
        while(!pq.empty()){
            tmp= pq.top();
            pq.pop();
            tmp+=pq.top();
            pq.pop();
            sol+=tmp;
            if(pq.empty())
                break;
            pq.push(tmp);
        }
        std::cout << sol<<'\n';

    }

};
int main(){
    card ca;
    ca.find_sol();
    return 0;
}