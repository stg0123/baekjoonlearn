#include <iostream>
using namespace std;
class cntZero{
private:
    int N,M;
public:
    cntZero(){
    }
    void findSol(){
        std::cin >> N >> M;
        int cnt =0;
        if(N==0)
            cnt++;
        for(int i=N;i<=M;i++){
            int val = i;
            while(val){
                cnt += !(val%10);
                val /= 10;
            }
        }
        std::cout << cnt << '\n';
    }
};
int main(){
    int N;
    std::cin >>N;
    cntZero cz;
    while(N--){
        cz.findSol();
    }
    return 0;
}