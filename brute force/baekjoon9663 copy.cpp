#include <iostream>
#include <vector>
using namespace std;
class nqueen{
private:
    vector<pair<int,int>> queen;
    int N;
    int sol;
public:
    nqueen(){
        std::cin >> N;
        sol=0;
    }
    bool check(int x,int y){
        for(pair<int,int> cur : queen){
            if(cur.first == x || cur.second == y || cur.first+cur.second == x+y || cur.first-cur.second == x-y)
                return false;
        }
        return true;
    };
    void dfs(int x,int y){
        if(!check(x,y))
            return ;
        if(queen.size()==N-1){
            sol++;
            return ;
        }
        for(int i=0;i<N;i++){
            queen.push_back({x,y});
            dfs(x+1,i);
            queen.pop_back();
        }
    }
    void find_sol(){
        for(int i=0;i<N;i++){
            dfs(0,i);
        }
        std::cout << sol <<'\n';
    }
};
int main(){
    nqueen nq;
    nq.find_sol();
    return 0;
}