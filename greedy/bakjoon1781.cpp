#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool compare(pair<int,int> A,pair<int,int> B){
    if(A.first==B.first)
        return A.second<B.second;
    return A.first<B.first;
};

class cup_raman{
private:
    vector<pair<int,int>> problem;
    int N;
public:
    cup_raman(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<N;i++){
            std::cin >> a >> b;
            problem.push_back({a,b});
        }
        sort(problem.begin(),problem.end(),compare);

    }

    void find_max(){
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<N;i++){
            pq.push(problem[i].second);
            while(pq.size()>problem[i].first)
                pq.pop();
        }
        int max =0;
        while(!pq.empty()){
            max+=pq.top();
            pq.pop();
        }
        std::cout << max << '\n';
    }

};
int main(){
    cup_raman cu;
    cu.find_max();

    return 0;
}