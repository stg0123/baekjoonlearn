#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000007
typedef long long l;
typedef vector<vector<l>> metrix;

class metrix_mul{
private:
    int N;
public:
    metrix_mul(int n):N(n){
        
    };
    metrix mul(metrix m1,metrix m2){
        metrix sol;
        l sum=0;
        sol.resize(m1.size());
        for(int i=0;i<m1.size();i++){
            for(int j=0;j<m2[0].size();j++){
                sum=0;
                for(int l=0;l<m2.size();l++)
                    sum+=(m1[i][l]*m2[l][j])%INF;
                sol[i].push_back(sum%INF);
            }
        }
        return sol;
    }

    void cal(){
        metrix m1,m2;
        int x,y,tmp;
        std::cin >>x>>y;
        m1.resize(x);
        for(int dx=0;dx<x;dx++){
            m1[dx].resize(y);
            for(int dy=0;dy<y;dy++)
                std::cin >>m1[dx][dy];
        }
        for(int i=1;i<N;i++){
            std::cin >> x>>y;
            m2.resize(x);
            for(int dx=0;dx<x;dx++){
                m2[dx].resize(y);   
                for(int dy=0;dy<y;dy++)
                    std::cin >> m2[dx][dy];
            }
            if(m1[0].size()!=x){
                std::cout << -1<<'\n';
                return ;
            }
            m1=mul(m1,m2);
        }
        l sol=0;
        for(int i=0;i<m1.size();i++)
            for(int j=0;j<m1[0].size();j++)
                sol=(sol+m1[i][j])%INF;

        std::cout << sol%INF<<'\n';

    }


};
int main(){
    int n;
    std::cin>>n;
    metrix_mul me(n);
    me.cal();

    return 0;
}