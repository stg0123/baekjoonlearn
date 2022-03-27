#include <iostream>
#include <vector>
using namespace std;
class route{
private:
    vector<vector<int>> map;
    vector<bool> visit;
    int N;
public:
    route(){
        std::cin >> N;
        map.resize(N);
        visit.resize(N);
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                std::cin >> tmp;
                map[i].push_back(tmp);
            }
        }
    }
    void dfs(int n){
        for(int i=0;i<N;i++){
            if(map[n][i]&&!visit[i]){
                visit[i]=true;
                dfs(i);
            }
        }
    }
    void find_sol(){
        for(int i=0;i<N;i++){
            fill(visit.begin(),visit.end(),false);
            dfs(i);
            for(int i=0;i<N;i++)
                std::cout << visit[i] << ' ';
            std::cout << '\n';
        }
    }
};
int main(){
    route rt;
    rt.find_sol();
    return 0;
}