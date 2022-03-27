#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
struct query{
    string operation;
    int branchNum;
};

struct compare{
    bool operator()(int& a,int& b){
        return a>b;
    }
};
class test1{
private:
    set<int> S;
    priority_queue<int,vector<int>,compare> remainNum;
    int N,maxNum;
public:
    test1(int n):N(n){
        maxNum =2;
        S.insert(1);
    }

    void startQueries(query * queries){
        for(int i=0;i<N;i++){
            if(queries[i].operation =="branch"){
                if(remainNum.empty())
                    S.insert(maxNum++);
                else{
                    S.insert(remainNum.top());
                    remainNum.pop();
                }
            }
            else if(queries[i].operation=="merge"){
                S.erase(queries[i].branchNum);
                remainNum.push(queries[i].branchNum);
            }
        }
    }

    void find_sol(){
        for(int i : S)
            std::cout << i << ' ';
    }


};