#include <iostream>
#include <vector>
using namespace std;
class app{
private:
    vector<pair<int,int>> map;
    vector<vector<int>> chache;
    int N,M,sum;
public :
    app(int n,int m):N(n),M(m){
        chache.resize(n+1);
        sum=0;
    }
    void set_val(){
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            map.push_back(make_pair(0,tmp));
        }
        for(int i=0;i<N;i++){
            std::cin >>map[i].first;
            sum+=map[i].first;
        }        
        for(int i=0;i<=N;i++)
            chache[i].resize(sum+1,0);
    };

    void knapsack(){
        for(int i=1;i<=N;i++)
            for(int j=1;j<=sum;j++){
                if(map[i-1].first<=j){
                    chache[i][j]=max(chache[i-1][j],chache[i-1][j-map[i-1].first]+map[i-1].second);
                }
                else
                {
                    chache[i][j]=chache[i-1][j];
                }
            }
        int sol=0;
        for(int i=1;i<=sum;i++)
            if(chache[N][i]>=M){
                sol=i;
                break;
            }
        std::cout <<sol <<'\n';
                
    };
    
    void print_chache(){
        std::cout << '\n';
        for(int i=0;i<=N;i++){
            for(int j=0;j<=sum;j++)
                std::cout << chache[i][j]<<' ';
            std::cout <<'\n';
        }
    }
};
int main(){
    int n,m;
    std::cin >> n >> m;
    app a(n,m);
    a.set_val();
    a.knapsack();
    return 0;
}