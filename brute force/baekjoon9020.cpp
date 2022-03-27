#include <iostream>
#include <vector>
using namespace std;
class golden{
private:
    vector<bool> prime_table;
    int N=10000;
public:
    golden(){
        prime_table.resize(N+1,true);
        prime_table[0]=prime_table[1]=false;
        for(int i=2;i<=N;i++){
            if(prime_table[i])
                for(int j=2;j<=N/i;j++)
                    prime_table[i*j]=false;
        }
    }
    void find(int a){
        int t = a/2;
        for(int i=0;i<=t;i++){
            if(prime_table[t-i] && prime_table[a-(t-i)]){
                std::cout << t-i << ' ' << a-(t-i) << '\n';
                return ;
            }
        }
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    golden gd;
    int t,a;
    std::cin >> t;
    for(int i=0;i<t;i++){
        std::cin >> a;
        gd.find(a);
    }
    
    return 0;
}