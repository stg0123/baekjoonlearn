#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<long long>> matrix;
class fibo{
private:
    long long N;
    int mod;
public:
    fibo(long long n):N(n){
        mod=1000000;
    };
    
    matrix ma_mul(const matrix& m1,const matrix& m2){
        matrix sol(m1.size(),vector<long long>(m2[0].size(),0));
        
        for(int i=0;i<m1.size();i++){
            for(int j=0;j<m2.size();j++){
                for(int l=0;l<m2[0].size();l++)
                    sol[i][j]+=(m1[i][l]*m2[l][j])%mod;
                sol[i][j]%=mod;
            }
        }
        return sol;
    }

    matrix pow(matrix& m1,long long p){
        if(p==1)
            return m1;
        if(p%2==1)
            return ma_mul(pow(m1,p-1),m1);
        matrix tmp=pow(m1,p/2);
        return ma_mul(tmp,tmp);
    };

    void find(){
        if(N<=1){
            std::cout <<N <<'\n';
            return ;
        }
        if(N==2){
            std::cout << 1<<'\n';
            return ;
        }


        matrix fibo_ma(2,vector<long long>(2,1));
        fibo_ma[1][1]=0;
        matrix tmp =pow(fibo_ma,N-1);
        std::cout << tmp[0][0]<<'\n';

    };

};
int main(){
    long long n;
    std::cin >> n;
    fibo f(n);
    f.find();

    return 0;
}