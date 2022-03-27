#include <iostream>
#include <vector>
using namespace std;
int INF=1000000000;
class mine{
private:
    vector<vector<int>> map;
    int N,M,B;
    int MAX=0,MIN=257;
public:
    mine(){
        std::cin >> N >> M >> B;
        map.resize(N,vector<int>(M));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                std::cin >> map[i][j];
                MAX=max(MAX,map[i][j]);
                MIN=min(MIN,map[i][j]);
            }
        }
    }
    int check(int d){
        int Block=B;
        int sol=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]>d){
                    sol+=2*(map[i][j]-d);
                    Block+=(map[i][j]-d);
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]<d){
                    sol+=(d-map[i][j]);
                    if(Block<(d-map[i][j]))
                        return INF;
                    Block-=(d-map[i][j]);
                }
            }
        }
        return sol;
    }
    void find_sol(){
        int sol1=INF,sol2=MAX;
        for(int i=MAX ;i>=MIN ;i--){
            int tmp =check(i);
            if(sol1>tmp){
                sol1=tmp;
                sol2=i;               
            }
        }
        std::cout << sol1 << ' '<<sol2 << '\n';
    }


};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    mine mn;
    mn.find_sol();
    return 0;
}