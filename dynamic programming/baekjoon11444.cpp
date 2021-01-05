#include <iostream>
#include <vector>

#define INF 1000000007
using namespace std;
typedef long long l;

class pibo{
private:
    vector<vector<l>> metrix;
    l N;
public:
    pibo(l n):N(n){
        metrix.resize(2);
        for(int i=0;i<2;i++)
            metrix[i].resize(2,1);
        metrix[1][1]=0;
        
        pibonachi(n);
    };

    vector<vector<l>> mul(vector<vector<l>> m1,vector<vector<l>> m2){
        vector<vector<l>> sol;
        sol.resize(m1.size());
        for(int i=0;i<m1.size();i++)
            sol[i].resize(m2[0].size(),0);
        for(int i=0;i<m1.size();i++)
            for(int j=0;j<m2[0].size();j++){
                for(int l=0;l<m2.size();l++)
                    sol[i][j]+=(m1[i][l]*m2[l][j])%INF;
                sol[i][j]%=INF;
            }
        
        return sol;
    }

    vector<vector<l>> pow(vector<vector<l>> m, l b){
        if(b==1)
            return m;

        if(b%2==0){
            vector<vector<l>> tmp=pow(m,b/2);
            return mul(tmp,tmp);
        }
        else
            return mul(pow(m,b-1),m);
    }

    void pibonachi(l n){
        if(n<=1){
            std::cout << n <<'\n';
            return ; 
        }
        vector<vector<l>> m(2,vector<l>(1));
        m[0][0]=1;
        m[1][0]=0; 

        std::cout << mul(pow(metrix,n-1),m)[0][0]%INF<<'\n';
        
    };
    
};
int main(){
    l n;
    std::cin >>n;
    pibo p(n);

    return 0;
}