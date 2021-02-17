#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
int powmod= 10007;
class fibo{
private:
    ll n;
public:
    fibo(){
        std::cin >> n;
    }
    matrix ma_mul(const matrix& a,const matrix& b){
        matrix sol(a.size(),vector<ll>(b[0].size(),0));
        for(int i=0;i<a.size();i++){
            for(int j=0;j<b[0].size();j++){
                for(int l=0;l<b.size();l++)
                    sol[i][j]+=(a[i][l]*b[l][j])%powmod;
                sol[i][j]%=powmod;
            }    
        }
        return sol;
    }
    matrix pow(matrix& a,ll p){
        if(p==1)
            return a;
        if(p%2==1)
            return ma_mul(pow(a,p-1),a);
        matrix tmp =pow(a,p/2);
        return ma_mul(tmp,tmp);
    }
    void start_fibo(){
        if(n<=1){
            std::cout << 1 << '\n';
            return ;
        }
        matrix id(2,vector<ll>(2,1));
        id[1][1]=0;
        std::cout << pow(id,n)[0][0];
    }

};
int main(){
    fibo f;
    f.start_fibo();

    return 0;
}