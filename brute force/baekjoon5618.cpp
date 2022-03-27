#include <iostream>
#include <vector>
using namespace std;
class commonDivisor{
private:
    int N;
    int GCD=0;
public:
    commonDivisor(){
        std::cin >> N;
        setVal();
    }
    void setVal(){
        for(int i=0;i<N;i++){
            int input;
            std::cin >> input;
            if(!GCD)
                GCD = input;
            else
                GCD = gcd(GCD,input);
        }
    }
    int gcd(int a,int b){
        return b ? gcd(b,a%b) : a;
    }
    void findSol(){
        for(int i=1;i<=GCD;i++){
            if(!(GCD%i))
                std::cout << i << '\n';
        }
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    commonDivisor cd;
    cd.findSol();
    return 0;
}