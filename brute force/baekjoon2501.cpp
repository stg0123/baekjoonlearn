#include <iostream>
using namespace std;
class divsor{
private:
    int N,K;
public:
    divsor(){
        std::cin >> N >> K;
    }
    void solution(){
        for(int i=1;i<10000;i++){
            if(N%i==0)
                K--;
            if(!K){
                std::cout << i << '\n';
                break;
            }
        }
        if(K)
            std::cout << 0 << '\n';
    }
};
int main(){
    divsor d1;
    d1.solution();
    return 0;
}