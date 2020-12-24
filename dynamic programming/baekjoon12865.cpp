#include <iostream>
#include <vector>
using namespace std;
class knapsack{
private:
    vector<pair<int,int>> map;
    vector<vector<int>> chache;
    int N,K;
public:
    knapsack(int n,int k):N(n),K(k){
        chache.resize(n+1);
        for(int i=0;i<=n;i++)
            chache[i].resize(k+1,0);
    };
    void set_val(){
        int tmp1,tmp2;
        for(int i=0;i<N;i++){
            std::cin >>tmp1 >>tmp2;
            map.push_back(make_pair(tmp1,tmp2));
        }
    };
    void dp(){
        for(int i=1;i<=N;i++)
            for(int j=1;j<=K;j++){
                if(map[i-1].first<=j)
                    chache[i][j]=max(chache[i-1][j],chache[i-1][j-map[i-1].first]+map[i-1].second);
                else
                    chache[i][j]=chache[i-1][j];        
            }
        std::cout << chache[N][K]<<'\n';                
    };


};
int main(){
    int n,k;
    std::cin>>n>>k;
    knapsack knap(n,k);
    knap.set_val();
    knap.dp();
    return 0;
}