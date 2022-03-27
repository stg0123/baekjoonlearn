#include <iostream>
#include <vector>
using namespace std;
class bretral{
private:
    vector<bool> prime_table;
    int N=300000;
public:
    bretral(){
        prime_table.resize(N,true);
        prime_table[0]=prime_table[1]=false;
        for(int i=2;i<=N;i++){
            if(prime_table[i])
                for(int j=2;j<=N/i;j++)
                    prime_table[i*j]=false;
        }
    }
    void find(int a){
        int sol=0;
        for(int i=a+1;i<=a*2;i++){
            if(prime_table[i])
                sol++;
        }
        std::cout << sol << '\n';
    }


};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    bretral bt;
    while(1){
        int a;
        std::cin >> a;
        if(!a)
            break;
        bt.find(a);
    }

    return 0;
}
