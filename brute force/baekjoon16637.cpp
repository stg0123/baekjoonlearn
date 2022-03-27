#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
ll INF= 10000000000;
class bracket{
private:
    string formula;
    vector<ll> result;
    int N;
    ll sol=-INF;
public:
    bracket(){
        std::cin >> N;
        std::cin >> formula;
    }
    void dfs(int cur,bool use){
        if(cur==N-1){
            ll tmp=result[0];
            for(int i=1;i<result.size();i++){
                if(i%2==0){
                    if(result[i-1]==0)
                        tmp+=result[i];
                    else if(result[i-1]==1)
                        tmp-=result[i];
                    else
                        tmp*=result[i];
                }
            }
            sol=max(sol,tmp);
            return ;
        }
        if(!use){
            ll save=result.back();
            ll tmp=save;
            if(formula[cur+1]=='+')
                tmp+=(formula[cur+2]-48);
            else if(formula[cur+1]=='-')
                tmp-=(formula[cur+2]-48);
            else
                tmp*=(formula[cur+2]-48);
            result.pop_back();
            result.push_back(tmp);
            dfs(cur+2,1);
            result.pop_back();
            result.push_back(save);
        }
        if(formula[cur+1]=='+')
            result.push_back(0);
        else if(formula[cur+1]=='-')
            result.push_back(1);
        else
            result.push_back(2);
        result.push_back(formula[cur+2]-48);
        dfs(cur+2,0);
        result.pop_back();
        result.pop_back();
    }
    void find_sol(){
        result.push_back(formula[0]-48);
        dfs(0,0);
        std::cout << sol << '\n';
    }

};
int main(){
    bracket bk;
    bk.find_sol();
    return 0;
}