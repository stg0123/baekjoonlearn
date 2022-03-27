#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class term_project{
private:
    vector<int> connect;
    vector<bool> visit,done;
    int N;
    int cnt=0;
public:
    term_project(){
        std::cin >> N;
        done.resize(N+1,false);
        visit.resize(N+1,false);
        connect.resize(N+1);
        set_val();
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> connect[i];
    }
    void dfs(int a){
        visit[a]=true;
        
        int next = connect[a];
        if(!visit[next])
            dfs(next);
        else if(!done[next]){
            for(int i=next; i!=a;i=connect[i])
                cnt++;
            cnt++;
        }
        done[a]=true;
    }
    void find_sol(){
        for(int i=1;i<=N;i++)
            if(!visit[i])
                dfs(i);
        std::cout << N-cnt<<'\n';
    }
};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        term_project tp;
        tp.find_sol();
    }
    return 0;
}