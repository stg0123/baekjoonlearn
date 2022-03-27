#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int INF=1000000000;
class chicken{
private:
    vector<vector<int>> edge;
    int N,M;
public:
    chicken(){
        std::cin >> N >>M;
        edge.resize(N);
        set_val();    
    }
    void set_val(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a>> b;
            a--,b--;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
    }
    int bfs(vector<bool>& start){
        vector<int> visit(N,-1);
        int sol=0;
        queue<int> q;
        for(int i=0;i<start.size();i++){
            if(start[i]){
                q.push(i);
                visit[i]=0;
            }
        }
        int cur;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            for(int i : edge[cur]){
                if(visit[i]==-1){
                    visit[i]=visit[cur]+1;
                    sol+=visit[i]*2;
                    q.push(i);
                }
            }
        }
        return sol;
    }
    void find_sol(){
        vector<bool> start(N,false);
        for(int i=0;i<2;i++)
            start[i]=true;
        int sol=INF,tmp;
        vector<bool> answer;
        do{
            tmp=bfs(start);
            if(sol>tmp){
                sol=tmp;
                answer=start;
            }          

        }while(prev_permutation(start.begin(),start.end()));
        for(int i=0;i<N;i++)
            if(answer[i])
                std::cout << i+1 << ' ';
        std::cout << sol << '\n';
    }



};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    chicken cc;
    cc.find_sol();

    return 0;
}