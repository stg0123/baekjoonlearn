#include <iostream>
#include <vector>
using namespace std;
class live{
private:
    vector<vector<long long>> map;
    int K,N;
public:
    live(int k,int n):K(k),N(n){
        map.resize(k+1);
        for(int i=0;i<=k;i++)
            map[i].resize(n+1,0);
        for(int i=0;i<=n;i++)
            map[0][i]=i;
        
    };
    long long cal(int k,int n){
        if(k==0)
            return n;
        if(map[k][n]!=0)
            return map[k][n];
        long long sum=0;
        for(int i=1;i<=n;i++){
            sum+=cal(k-1,i);
        }
        map[k][n]=sum;
        return sum;
    };
    void print_map(){
        std::cout <<'\n';
        for(int i=0;i<=K;i++){
            for(int j=0;j<=N;j++)
                std::cout << map[i][j]<< ' ';
        std::cout << '\n';
        }
    };

};

int main()
{
    int m,k,n;
    std::cin >> m;
    for(int i=0;i<m;i++){
        std::cin >>k >> n;
        live l(k,n);
        std::cout << l.cal(k,n)<<'\n';
    }
    return 0;
}