#include <iostream>
#include <vector>
using namespace std;
class coin{
private:
    vector<int> val;
    vector<int> dp_n;
    vector<int> dp_k;
    int N,K;
public:
    coin(int n,int k):N(n),K(k){
        val.resize(n+1);
        dp_n.resize(k+1,0);
        dp_k.resize(k+1,0);
    };
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> val[i];
    }
    void DP(){
        dp_n[0]=1;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=K;j++){
                if(j<val[i])
                    dp_n[j]=dp_k[j];
                else
                    dp_n[j]=dp_k[j]+ dp_n[j-val[i]];
            }
            dp_k=dp_n;
        }
        std::cout << dp_n[K]<<'\n';
    }
};
int main(){
    int n,k;
    std::cin >> n >> k;
    coin c(n,k);
    c.set_val();
    c.DP();
    

    return 0;
}