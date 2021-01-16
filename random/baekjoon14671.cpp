#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m,k;
    std::cin >> n >> m >> k;
    vector<vector<bool>> map(2,vector<bool>(2));
    for(int i=0;i<k;i++){
        std::cin >> n>>m;
            map[(n+m)%2][m%2]=true;
    }    
    
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(!map[i][j]){
                std::cout << "NO\n";
                return 0;
            }
    std::cout << "YES\n";
    return 0;
}