#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Gumminsu{
private:
    int N;
public:
    Gumminsu(){
        std::cin >> N;
    }
    void findSol(){        
        while(N){
            if(isGum(N)){
                std::cout << N << '\n';
                break;
            }
            N--;
        }
    }
    bool isGum(int n){
        while(n){
            if(n%10 == 7 || n%10 == 4)
                n/=10;
            else    
                return false;
        }
        return true;
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    Gumminsu Gms;
    Gms.findSol();
    return 0;
}