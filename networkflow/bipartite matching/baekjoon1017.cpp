#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class prime_pair{
private:
    vector<int> v1,v2;
    vector<bool> visit;
    vector<int> sol;
    vector<vector<int>> link;
    vector<bool> prime_table;
    int max,first;
    int N;
public:
    prime_pair(){
        std::cin >> N;
        max=2000;
        link.resize(N/2);
        sol.resize(N/2);
        visit.resize(N/2);
        prime_table.resize(max+1,true);
        for(int i=2;i<max;i++){
            if(prime_table[i]==true){
                for(int j=i;j<=max/i;j++){
                    prime_table[i*j]=false;
                }
            }
        }
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            if(i==0)
                first=tmp;
            if(tmp%2==0)
                v1.push_back(tmp);
            else
                v2.push_back(tmp);
        }
    }
    int dfs(int n){
        if(visit[n])
            return 0;
        visit[n]=true;
        for(int i : link[n]){
            if(sol[i]==-1 || dfs(sol[i])){
                sol[i]=n;
                return 1;
            }
        }
        return 0;
    }
    void start_dfs(){
        if(v1.size()!=v2.size()){
            std::cout << -1 <<'\n';
            return ;
        }
        if(first%2==1)
            swap(v1,v2);
        
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                if(prime_table[v1[i]+v2[j]])
                    link[i].push_back(j);
            }
        }
        int line;
        vector<int> answer;
        for(int data : link[0]){
            line =1;
            fill(sol.begin(),sol.end(),-1);
            sol[data]=0;
            for(int i=1;i<v1.size();i++){
                fill(visit.begin(),visit.end(),false);
                visit[0]=true;
                line +=dfs(i);
            }
            if(line== v1.size())
                answer.push_back(v2[data]);
        }
        if(answer.empty()){
            std::cout << -1 ;
            return ;
        }
        sort(answer.begin(),answer.end());
        for(int i=0;i<answer.size();i++){
            std::cout << answer[i] <<' ';
        }

    }


};
int main(){
    prime_pair pp;
    pp.start_dfs();
    return 0;
}