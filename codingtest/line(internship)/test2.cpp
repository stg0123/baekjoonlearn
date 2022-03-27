#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int INF=1000000000;
class test2{
private:
    vector<vector<int>> gunban;
    vector<int> music;
    int N= 13;
public:
    test2(vector<int> m):music(m){
        set_val();
    }
    void set_val(){
        gunban.resize(13);
        for(int i=1;i<N-1;i++){
            gunban[i].push_back(i+1);
            gunban[i+1].push_back(i);
            if((i<7 && i%2) || (i>7 && !(i%2))){
                gunban[i].push_back(i+2);    
                gunban[i+2].push_back(i);
            }
        }

    }
    int bfs(int start,int end){
        vector<bool> visit(N,false);
        queue<pair<int,int>> q;
        q.push({start,0});
        visit[start]=true;
        pair<int,int> cur;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur.first == end)
                return cur.second;
        
            for(int next : gunban[cur.first]){
                if(next<N && next>0){
                    if(!visit[next]){
                        visit[next]=true;
                        q.push({next,cur.second+1});
                    }
                }
            }
        }
        return 0;
    }
    int find_sol(){
        int cur = 1;
        int sol=0;
        for(int i : music){
            sol+=bfs(cur,i);
            cur=i;
        }
        return sol;
    }

};
int main(){
    test2 t2({10,9,4,5,12});
    std::cout << t2.find_sol()<<"\n";


    return 0;
}
