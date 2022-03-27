#include <iostream>
#include <vector>
using namespace std;
class factorization{
private:
    vector<bool> prime_table;
    int N=10000000;
public:
    factorization(){
        prime_table.resize(N+1,true);
        prime_table[0]=prime_table[1]=false;
        for(int i=2;i<=N;i++){
            if(prime_table[i])
                for(int j=2;j<=N/i;j++)
                    prime_table[i*j]=false;
        }
    }
    void find(){
        int a;
        std::cin >> a;
        while(a>1){
            for(int i=2;i<=a;i++){
                if(prime_table[i] && !(a%i)){
                    std::cout << i << '\n';
                    a/=i;
                    break;
                }
            }
        }
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    factorization ft;
    ft.find();
    return 0;
}