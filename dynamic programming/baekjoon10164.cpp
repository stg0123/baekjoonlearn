#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class root{
private:
    vector<vector<ll>> pascal;
    int N,M,K;
public:
    root(){
        std::cin >> N >> M >>K;
        pascal.resize(N+M+1,vector<ll>(N+M+1));
        pascal[0][0]=1;
    }
    ll DP(int n,int m){
        if(n<m || m<0)
            return 0;
        if(pascal[n][m])
            return pascal[n][m];
        pascal[n][m]=DP(n-1,m-1)+DP(n-1,m);
        return pascal[n][m];
    }
    void find_sol(){
        if(K){
            int row = (K-1)/M;
            int col = (K-1)%M;
            std::cout << DP(row+col,col)*DP(N-row-1+M-col-1,N-1-row) << '\n';
        }
        else
            std::cout << DP(N-1+M-1,N-1)<<'\n';

    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    root rt;
    rt.find_sol();   

    return 0;
}