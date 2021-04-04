#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
int powmod=1e9;
class fibo{
private:
    ll a,b;
public:
    fibo(){
        std::cin >>a >> b;
    }
    matrix m_mul(matrix a,matrix b){
        matrix sol;
        sol.resize(a.size(),vector<ll>(b[0].size()));
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b[0].size();j++){
                for(int l=0;l<b.size();l++){
                    sol[i][j]+=a[i][l]*b[l][j]%powmod;
                }
                sol[i][j]%=powmod;
            }
        }
        return sol;
    }
    matrix m_pow(matrix& a,ll p){
        if(p==1)
            return a;
        if(p%2==1)
            return m_mul(m_pow(a,p-1),a);
        matrix tmp = m_pow(a,p/2);
        return m_mul(tmp,tmp);
    }
    ll find_fibo(ll n){
        if(n==1){
            return 1;
        }
        matrix id(2,vector<ll>(2,1));
        id[1][1]=0;
        return m_pow(id,n-1)[0][0];
    }
    void find_sol(){
        int tmp =find_fibo(b+2)-find_fibo(a+1);
        if(tmp<0)
            std::cout << tmp+powmod;
        else
            std::cout << tmp;
    }


};
int main(){
    fibo f;
    f.find_sol();
    return 0;
}