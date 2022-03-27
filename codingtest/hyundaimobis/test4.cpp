#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
struct compare{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return a.second == b.second ? a.first> b.first : a.second<b.second;
    }
};
class test4{
private:
    unordered_set<int> S;
    vector<int> sum;
    int N;
public:
    test4(int n):N(n){
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        sum.resize(N+1,0);
        for(int i=1;i<=N;i++)
            pq.push({i,sum[i]});
        for(int i=0;i<N/2;i++){
            S.insert(pq.top().first);
            pq.pop();
        }
    }
    int find_sol(vector<int>& student,vector<int>& point){
        int count=0;
        for(int i=0;i<student.size();i++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
            unordered_set<int> tmp_S;
            sum[student[i]]+=point[i];
            for(int j=1;j<=N;j++)
                pq.push({j,sum[j]});
            for(int j=0;j<N/2;j++){
                tmp_S.insert(pq.top().first);
                pq.pop();
            }
            if(S!=tmp_S){
                count++;
                S=tmp_S;
            }            
        }
        return count;
    }

};