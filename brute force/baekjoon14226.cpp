#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class imoticon{
private:
    queue<pair<int,int>> q;
    vector<vector<bool>> visit;
    int S;
public:
    imoticon(){
        std::cin >> S;
        visit.resize(S*2,vector<bool>(S*2,false));
        q.push({1,0});
    }
    bool bfs(){
        queue<pair<int,int>> nq;
        pair<int,int> cur;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur.first==S)
                return true;
            if(!visit[cur.first][cur.first]){
                visit[cur.first][cur.first]=true;
                nq.push({cur.first,cur.first});
            }
            if(cur.first+cur.second<S*2){
                if(!visit[cur.first+cur.second][cur.second]){
                    visit[cur.first+cur.second][cur.second]=true;
                    nq.push({cur.first+cur.second,cur.second});
                }
            }
            if(cur.first>1 && !visit[cur.first-1][cur.second]){
                visit[cur.first-1][cur.second]=true;
                nq.push({cur.first-1,cur.second});
            }
        }
        q=nq;
        return false;
    }
    void find_sol(){
        int sol =0;
        visit[1][0]=true;
        while(!bfs())
            sol++;

        std::cout << sol << '\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    imoticon imc;
    imc.find_sol();

    return 0;
}