#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
int powmod=1e9+7;
class three_tile{
private:
    ll N;
public:
    three_tile(){
        std::cin >> N;

    }
    matrix ma_mul(const matrix& a,const matrix& b){
        matrix sol(a.size(),vector<ll>(b[0].size(),0));
        for(int i=0;i<a.size();i++)
            for(int j=0;j<b[0].size();j++){
                for(int l=0;l<b.size();l++)
                    sol[i][j]+=(a[i][l]*b[l][j]+powmod)%powmod;
                sol[i][j]%=powmod;
            } 
        return sol;
    }
    matrix pow(matrix& a,ll p){
        if(p==1)
            return a;
        if(p%2==1)
            return ma_mul(pow(a,p-1),a);
        matrix tmp = pow(a,p/2);
        return ma_mul(tmp,tmp);
    }
    void find_sol(){
        if(N%2==1){
            std::cout << 0 << '\n';
            return ;
        }
        if(N==2){
            std::cout << 3 << '\n';
            return ;
        }
            
        matrix id(2,vector<ll>(2,0));
        id[0][0]=4;
        id[0][1]=-1;
        id[1][0]=1;
        matrix tmp = pow(id,N/2-1);
        std::cout << (tmp[0][0]*3%powmod +tmp[0][1]%powmod)%powmod<<'\n';

    }

};
int main(){
    three_tile tt;
    tt.find_sol();
    return 0;
}