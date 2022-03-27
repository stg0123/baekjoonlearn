#include <iostream>
#include <vector>
using namespace std;
struct friends_pair{
    int a,b;
};
class test3{
private:
    vector<vector<bool>> pair;
    vector<bool> visit;
    int N;
public:
    test3(int n, friends_pair * pairs):N(n){
        pair.resize(9,vector<bool>(9,false));
        visit.resize(9,false);
        for(int i=0;i<n;i++){
            pair[pairs[i].a][pairs[i].b]=true;
            pair[pairs[i].b][pairs[i].a]=true;
        }
    }

    int dfs(int depth,int lastChild){
        if(depth == 8)
            return 1;
        int sol=0;
        for(int i=1;i<9;i++){
            if(!visit[i] && !pair[lastChild][i]){
                visit[i]=true;
                sol+=dfs(depth+1,i);
                visit[i]=false;
            }
        }
        return sol;
    }
    void find_sol(){
        std::cout << dfs(0,0);

    }

};