#include <iostream>
#include <vector>
#define INF 1000000
using namespace std;
class Goldbach{
private:
    vector<bool> prime_table;
public:
    Goldbach(){
        prime_table.resize(INF+1,true);
        prime_table[0]=prime_table[1]=false;
        for(int i=2;i<=INF/2;i++){
            if(prime_table[i]==true){
                for(int j=i;j<=INF/i;j++){
                    prime_table[i*j]=false;
                }
            }
        }
    }
    void find_sol(int N){
        for(int i=2;i<INF/2;i++){
            if(prime_table[i]==true&&prime_table[N-i]==true){
                std::cout << N <<" = "<<i <<" + "<<N-i <<'\n';
                return ;
            }
        }
        std::cout << "Goldbach's conjecture is wrong.";
    }


};
int main(){
    Goldbach gb;
    int n;
    while(1){
        std::cin >> n;
        if(n==0)
            break;
        gb.find_sol(n);
    }
    

}