#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct compare{
    bool operator()(int& a,int& b){
        return a>b;
    };
};
class _union{
private:
    priority_queue<int> plus;
    priority_queue<int,vector<int>,compare> minus;
    int N;
public:
    _union(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            if(tmp>0)
                plus.push(tmp);
            else
                minus.push(tmp);
        }
    }
    void find_sol(){
        int sol=0;
        int tmp;
        while(!plus.empty()){
            tmp =plus.top();
            plus.pop();
            if(plus.empty()){
                sol+=tmp;
                break;
            }
            if(plus.top()==1)
                sol+=plus.top()+tmp;
            else
                sol+=plus.top()*tmp;
            plus.pop();
        }
        while(!minus.empty()){
            tmp=minus.top();
            minus.pop();
            if(minus.empty()){
                sol+=tmp;
                break;
            }
            sol+=minus.top()*tmp;
            minus.pop();
        }
        std::cout << sol;

    }

    
};
int main(){
    _union un;
    un.find_sol();
    return 0;
}