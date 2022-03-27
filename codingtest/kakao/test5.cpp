#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct node{
    int iswolf;
    int parent;
    vector<int> child;
};
struct node2{
    int cur_sheep=-1;
    int cur_wolf=-1;
};
class test5{
private:
    vector<node> tree;
    vector<node2> dp;
    int root=0;
    int cur_sheep=0,cur_wolf=0;
public:
    test5(vector<int>& info,vector<vector<int>>& edges){
        tree.resize(info.size());
        dp.resize(info.size());
        for(int i=0;i<info.size();i++)
            tree[i].iswolf=info[i];
        for(int i=0;i<edges.size();i++){
            tree[edges[i][0]].child.push_back(edges[i][1]);
            tree[edges[i][1]].parent=edges[i][0];
        }
        tree[0].iswolf=0;
        
    }
    node2 DP(int n){
        if(dp[n].cur_sheep!=-1)
            return dp[n];
        dp[n]={0,0};
        int max=0;
        node2 tmp;
        for(int i : tree[n].child){
            tmp =DP(i);
            dp[n].cur_sheep+=tmp.cur_sheep;
            dp[n].cur_wolf+=tmp.cur_wolf;
        }
        if(tree[n].iswolf)
            dp[n].cur_wolf++;
        else
            dp[n].cur_sheep++;
        return dp[n];
    }
    int find_sol(){
        return DP(root).cur_sheep;
    }
};
int solution(vector<int> info, vector<vector<int>> edges) {
    test5 t5(info,edges);
    return t5.find_sol();
}
int main(){
    solution({0,0,1,1,1,0,1,0,1,0,1,1},{{0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}});

    return 0;
}