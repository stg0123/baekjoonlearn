#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct _node{
    int pre;
    vector<int> edge;
};
class line_sort{
private:
    vector<_node> student;
    int N,M;
public:
    line_sort(){
        std::cin >> N >> M;
        student.resize(N+1,{0,});
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<M;i++){
            std::cin >> a>>b;
            student[a].edge.push_back(b);
            student[b].pre++;
        }
    }
    void bfs(){
        queue<int> q;
        vector<int> sol;
        for(int i=1;i<=N;i++)
            if(student[i].pre==0)
                q.push(i);
        int cur,tmp;
        while(!q.empty()){
            cur =q.front();
            q.pop();
            sol.push_back(cur);
            for(int i=0;i<student[cur].edge.size();i++){
                tmp =student[cur].edge[i];
                if(--(student[tmp].pre)==0)
                    q.push(tmp);
            }
        }
        for(int i=0;i<sol.size();i++)
            std::cout << sol[i] << ' ';
    }
};
int main(){
    line_sort ls;
    ls.bfs();
    return 0;
}