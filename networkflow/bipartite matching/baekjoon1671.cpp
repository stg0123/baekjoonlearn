#include <iostream>
#include <vector>
using namespace std;
struct _node{
    int x,y,z;
    bool operator<=(_node& a){
        return x<=a.x&&y<=a.y&&z<=a.z;
    }
    bool operator ==(_node& a){
        return x==a.x&&y==a.y&&z==a.z;
    }
};
class bi_matching{
private:
    vector<vector<int>> link;
    vector<_node> val;
    vector<int> sol;
    vector<bool> visit;
    int N;
public:
    bi_matching(){
        std::cin >> N;
        link.resize(N);
        visit.resize(N);
        sol.resize(N,-1);
        set_val();
    }
    void set_val(){
        int x,y,z;
        for(int i=0;i<N;i++){
            std::cin >> x >>y >>z;
            val.push_back({x,y,z});
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j)
                    continue;
                if(val[j]<=val[i]){
                    if(val[i]==val[j]&&i>j);
                    else
                        link[i].push_back(j);
                }
            }
        }
    }
    int dfs(int n){
        if(visit[n])
            return 0;
        visit[n]=true;
        for(int i : link[n]){
            if(sol[i]==-1||dfs(sol[i])){
                sol[i]=n;
                return 1;
            }
        }
        return 0;
    }
    void start_dfs(){
        int res=0;
        for(int n=0;n<2;n++){
            for(int i=0;i<N;i++){
                fill(visit.begin(),visit.end(),false);
                res+= dfs(i);
            }
        }
        std::cout << N-res;
    }

};
int main(){
    bi_matching bm;
    bm.start_dfs();
    return 0;
}