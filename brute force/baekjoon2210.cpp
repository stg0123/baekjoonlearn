#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
struct _node{
    int depth;
    int x,y;
    string str;
};
class numbering{
private:
    vector<vector<char>> map;
    unordered_set<string> S;
public:
    numbering(){
        map.resize(5,vector<char>(5));
        set_val();
    }
    void set_val(){
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                std::cin >> map[i][j];
    }
    void dfs(int x,int y){
        stack<_node> st;
        string tmp;
        tmp.push_back(map[x][y]);
        st.push({0,x,y,tmp});
        _node cur;
        int nx,ny;
        while(!st.empty()){
            cur = st.top();
            st.pop();
            if(cur.depth==5){
                S.insert(cur.str);
                continue;
            }
            for(int i=0;i<4;i++){
                nx =cur.x+dx[i],ny=cur.y+dy[i];
                if(nx>=0 && nx<5 && ny>=0 && ny<5){
                    st.push({cur.depth+1,nx,ny,cur.str+map[nx][ny]});
                }
            }
        }
    }
    void find_sol(){
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                dfs(i,j);
        std::cout << S.size() << '\n';
    }
};
int main(){
    numbering nb;
    nb.find_sol();
    return 0;
}