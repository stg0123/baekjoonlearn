#include <iostream>
#include <vector>
using namespace std;
class grape{
private:
    vector<vector<int>> chache;
    vector<int> map;
    int N;
public:
    grape(int n):N(n){
        chache.resize(n+1);
        for(int i=1;i<=n;i++)
            chache[i].resize(2,-1);
        map.resize(n+1,0);
    };

    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >>map[i];
        chache[1][0]=map[1];
        chache[1][1]=map[1];
        if(N>1){
            chache[2][0]=map[1]+map[2];
            chache[2][1]=map[1]+map[2];
        }
    };

    int DP(int n,int m){
        if(n<=0)
            return 0;
        else if(chache[n][m]!=-1)
            return chache[n][m];
        int tmp1;
        if(m==0){
            tmp1=max(DP(n-3,0)+map[n-1]+map[n],DP(n-2,0)+map[n]);
            chache[n][m]=max(tmp1,DP(n-4,0)+map[n-1]+map[n]);
        }
        else
            chache[n][m]=DP(n-1,0);

        return chache[n][m];
    };
    void print_val(){
        std::cout << max(DP(N,0),DP(N,1))<<'\n';
    };

};

int main(){
    int n;
    std::cin >> n;
    grape g(n);
    g.set_val();
    g.print_val();

    return 0;
}