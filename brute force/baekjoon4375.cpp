#include <iostream>
using namespace std;
class one{
public:
    one(){
    }
    void find_sol(int n){
        int sol=1;
        int mod=1%n;
        while(mod){
            mod=mod*10+1;
            mod%=n;
            sol++;
        }
        std::cout << sol << '\n';
    }


};
int main(){
    one o;
    int n;
    while(std::cin >> n){
        o.find_sol(n);
    }

    return 0;
}