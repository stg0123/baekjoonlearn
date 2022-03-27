#include <iostream>
#include <vector>
using namespace std;
class bottle{
private:
    int N,K;
public:
    bottle(){
        std::cin >>N >>K;
    }
    int find_water(int a){
        int sol=0;
        while(a){
            sol+=a%2;
            a>>=1;
        }
        return sol;
    }
    void find_sol(){
        int sol=0;
        while(find_water(N++)>K){
            sol++;
        }
        std::cout << sol << '\n';
    }

};

int main(){
    bottle bt;
    bt.find_sol();

    return 0;
}