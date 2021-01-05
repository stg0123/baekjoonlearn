#include <iostream>
#include <vector>
using namespace std;
class pascal{
private:
    vector<vector<long long>> map;
    int N,M;
public:
    pascal(int n,int m):N(n),M(m){
        map.resize(n+1);
        for(int i=1;i<=N;i++)
            map[i].resize(i,0);
    }

    long long combination(int n,int m){
        if(n==m||m==0)
            return 1;
        else if(map[n][m]!=0)
            return map[n][m];
            
        map[n][m]=combination(n-1,m)+combination(n-1,m-1);
        return map[n][m];
    }

};

int main(){
    int n,a,b;
    std::cin >> n;
    pascal p(30,30);
    for(int i=0;i<n;i++){
        std::cin >> a>>b;
        std::cout << p.combination(b,a)<<'\n';

    }        

    return 0;
}