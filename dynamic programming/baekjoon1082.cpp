#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class max_num{
private:
    vector<int> val;
    vector<int> sol;
    int N;
    int MONEY;
public:
    max_num(int n):N(n){
        val.resize(n);
    }
    void set_val(){
        if(N==1){
            std::cout <<0 <<'\n';
            return ;
        }
        for(int i=0;i<N;i++){
            std::cin >> val[i];
        }
        std::cin >> MONEY;
        sol.push_back(min_element(val.begin()+1,val.end())-val.begin());
        MONEY-=val[sol[0]];
        if(MONEY<0){
            std::cout << 0 << '\n';
            return ;
        }
        int tmp = min_element(val.begin(),val.end())-val.begin();
        for(int i=0;i<MONEY/val[tmp];i++)
            sol.push_back(tmp);
        MONEY%=val[tmp];
        DP(0);
        print_sol();
    }
    void print_sol(){
        for(int i=0;i<sol.size();i++)
            std::cout << sol[i] ;
        std::cout <<'\n';
    }
    
    void DP(int n){
        if(n>=sol.size()||MONEY<0)
            return ;
        for(int i=N-1;i>0&&sol[n]<i;i--){
            int tmp =val[i]-val[sol[n]];
            if(MONEY>=tmp){
                sol[n]=i;
                MONEY-=tmp;
            }
        }
        DP(n+1);
    }
};
int main(){
    int n;
    std::cin >> n;
    max_num ma(n);
    ma.set_val();
    return 0;
}
