#include <iostream>
#include <vector>
using namespace std;
class prefixsum{
private:
    vector<vector<int>> map;
    int N,M;
public:
    prefixsum(){
        std::cin >> N >> M;
        map.resize(N+1,vector<int>(M+1,0));
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                std::cin >> tmp;
                map[i][j]=map[i-1][j]+map[i][j-1]-map[i-1][j-1]+tmp;
            }
        }
    }
    void find_sol(){
        int x1,y1,x2,y2;
        int n;
        std::cin >> n;
        for(int i=0;i<n;i++){
            std::cin >> x1 >>y1>>x2>>y2;
            std::cout << map[x2][y2]-map[x1-1][y2]-map[x2][y1-1]+map[x1-1][y1-1]<<'\n';
        }
    }


};
int main(){
    prefixsum pf;
    pf.find_sol();
    return 0;
}