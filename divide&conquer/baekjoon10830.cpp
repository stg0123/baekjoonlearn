#include <iostream>
#include <vector>
using namespace std;
typedef long long l;
class metrix_pow{
private:
    vector<vector<l>> metrix;
    l N,P;
public:
    metrix_pow(l n,l p):N(n),P(p){
        metrix.resize(n);
    };
    void set_val(){
        int tmp;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++){
                std::cin >> tmp;
                metrix[i].push_back(tmp);
            }
    };
    void start(){
        vector<vector<l>> tmp=pow(metrix,P);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                std::cout << tmp[i][j]%1000<< ' ';
            std::cout <<'\n';
        }
    }
    
    vector<vector<l>> me_mul(vector<vector<l>> m1,vector<vector<l>> m2){
        vector<vector<l>> sol;
        sol.resize(N);
        l sum;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                sum=0;
                for(int l=0;l<N;l++)
                    sum+=(m1[i][l]*m2[l][j])%1000;
                sol[i].push_back(sum%1000);
            }
        }
        return sol;
    };

    vector<vector<l>> pow(vector<vector<l>> me,l p){
        if(p==1)
            return me;
        if(p%2==1)
            return me_mul(pow(me,p-1),me);
        vector<vector<l>> tmp = pow(me,p/2);
        return me_mul(tmp,tmp);
    }
};
int main(){
    l n,m;

    std::cin >>n >> m;
    metrix_pow metrix(n,m);
    metrix.set_val();
    metrix.start();
    return 0;
}