#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class function_oper{
private:
    vector<vector<int>> sparse;
    int N,MAX_cycle,MAX_pow;
public:
    function_oper(){
        std::cin>> N;
        MAX_cycle=500000;
        MAX_pow=(int)floor(log2(MAX_cycle));
        sparse.resize(N+1,vector<int>(MAX_pow+1,-1));
        set_res();
    }
    void set_res(){
        for(int i=1;i<=N;i++)
            std::cin >> sparse[i][0];
        for(int i=1;i<=MAX_pow;i++)
            for(int j=1;j<=N;j++)
                sparse[j][i]=sparse[sparse[j][i-1]][i-1];
    }
    int DP(int val,int n){
        if(sparse[val][n]!=-1)
            return sparse[val][n];
        sparse[val][n]=DP(DP(val,n-1),n-1);
        return sparse[val][n];
    }
    void re_func(int n,int val){
        for(int i=MAX_pow;i>=0;i--){
            if(n>=(1<<i)){
                n-=(1<<i);
                val=sparse[val][i];
            }
            if(n==0)
                break;
        }
        std::cout << val << '\n';
    }


};
int main(){
    function_oper fo;
    int n,a,b;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> a >>b;
        fo.re_func(a,b);
    }


    return 0;
}