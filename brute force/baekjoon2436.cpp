#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class gcdlcm{
private:
    int GCD,LCM;
public:
    gcdlcm(){
        std::cin >> GCD >> LCM;
        
    };

    int gcd(int a,int b){
        return b ? gcd(b,a%b) : a;
    }
    void find_sol(){
        if(LCM%GCD)
            return ;
        int tmp = LCM/GCD;
        pair<int,int> sol;
        for(int i=1;i<=tmp;i++){
            if(i>tmp/i)
                break;
            if(tmp%i==0 && gcd(i,tmp/i)==1){
                sol={i,tmp/i};
            }
        }
        std::cout << GCD*sol.first <<' ' << GCD*sol.second << '\n';

    }



};
int main(){
    gcdlcm gl;
    gl.find_sol();

    return 0;
}