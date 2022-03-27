#include <iostream>
#include <vector>
using namespace std;
class divisor{
private:
    int N,F;
public:
    divisor(){
        std::cin >> N >> F;
        N -=(N%100);
    }
    void find_sol(){
        for(int i=0;i<100;i++){
            if(N%F==0){
                int sol = N%100;
                if(sol<10)
                    std::cout << '0';
                std::cout << sol << '\n';
                return ;
            }
            N++;
        }
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    divisor di;
    di.find_sol();
    return 0;
}
