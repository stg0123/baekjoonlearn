#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct compare{
    bool operator()(int& a,int& b){
        return a<b;
    }
};
class test3{
private:
    priority_queue<int,vector<int>,compare> pq1;
    int A,B;
public:
    test3(vector<int> v,int a,int b):A(a),B(b){
        for(int i : v)
            pq1.push(i);
    }
    int find_sol(){
        int i=0;
        while(1){
            if(pq1.top()<A)
                break;
            priority_queue<int,vector<int>,compare> pq2;
            pq2.push(pq1.top()-A);
            pq1.pop();
            while(!pq1.empty()){
                pq2.push(pq1.top()-B);
                pq1.pop();
            }
            pq1=pq2;
            i++;
        }
        return i;
    }


};
int main(){
    test3 t3({4,5,5},2,1);
    std::cout << t3.find_sol()<<'\n';

    return 0;
}

