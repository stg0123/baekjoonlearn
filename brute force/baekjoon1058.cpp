#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class friends{
private:
    vector<vector<bool>> disjoint;
    int N;
public:
    friends(){
        std::cin >> N;
        disjoint.resize(N,vector<bool>(N));
        set_val();

    }
    void set_val(){
        string str;
        for(int i=0;i<N;i++){
            std::cin >> str;
            for(int j=0;j<str.size();j++){
                if(str[j]=='N')
                    disjoint[i][j]=false;
                else
                    disjoint[i][j]=true;
            }
        }
    }

    int bfs(int start){
        queue<pair<int,int>> q;
        vector<bool> visit(N,false);
        visit[start]=true;
        q.push({start,0});
        int count=0;
        pair<int,int> cur;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur.second==2)
                continue;
            for(int i=0;i<N;i++){
                if(disjoint[cur.first][i] && !visit[i]){
                    visit[i]=true;
                    count++;
                    q.push({i,cur.second+1});
                }
            }
        }
        return count;
    }

    void find_sol(){
        int sol=0;
        for(int i=0;i<N;i++){
            sol=max(sol,bfs(i));
        }
        std::cout << sol << '\n';
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    friends fr;
    fr.find_sol();


    return 0;
}