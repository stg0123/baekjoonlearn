#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
class test3{
private:
    vector<pair<int,int>> work_time_prior; // 시간 ,중요도 
public:
    test3(){
        work_time_prior.resize(101,{0,0});
    }
    vector<int> find_sol(vector<vector<int>>& jobs){
        int cur_time=jobs[0][0]+jobs[0][1];
        int cur_work=jobs[0][2];
        int cur =1;
        int same_work=0;
        pair<int,int> max_prior={0,0}; // 중요도 , 작업분류
        vector<int> sol;
        sol.push_back(jobs[0][2]);
        while(cur<jobs.size()){
            while(jobs[cur][0]<=cur_time){
                if(jobs[cur][2]==cur_work)
                    same_work+=jobs[cur][1];
                else{
                    work_time_prior[jobs[cur][2]].first+=jobs[cur][1];
                    work_time_prior[jobs[cur][2]].second+=jobs[cur][3];
                    if(max_prior.first<work_time_prior[jobs[cur][2]].second || (max_prior.first==work_time_prior[jobs[cur][2]].second && max_prior.second>jobs[cur][2])){
                        max_prior.first=work_time_prior[jobs[cur][2]].second;
                        max_prior.second=jobs[cur][2];
                    }
                }
                cur++;
                
            }
            if(same_work){
                cur_time+=same_work;
                same_work=0;
            }
            else{
                cur_work=max_prior.second;
                sol.push_back(cur_work);
                cur_time=work_time_prior[cur_work].first;
                work_time_prior[cur_work]={0,0};
                max_prior={0,0};
                for(int i=1;i<work_time_prior.size();i++){
                    if(max_prior.first<work_time_prior[i].second || (max_prior.first==work_time_prior[i].second && max_prior.second>i) ){
                        max_prior.first=work_time_prior[i].second;
                        max_prior.second=i;
                    }
                }
            }
        }
        return sol;
    }


};

vector<int> solution(vector<vector<int>> jobs) {
    test3 t3;
    return t3.find_sol(jobs);
};

int main(){
    vector<int> sol = solution({{1, 5, 2, 3}, {2, 2, 3, 2}, {3, 1, 3, 3}, {5, 2, 1, 5}, {7, 1, 1, 1}, {9, 1, 1, 1}, {10, 2, 2, 9}});
    for(int i=0;i<sol.size();i++){
        std::cout << sol[i] << ' ';
    }

    return 0;
}