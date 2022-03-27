#include <iostream>
#include <vector>
using namespace std;
class tile{
private:
    int R,B;
public:
    tile(){
        std::cin >> R >> B ;

    }
    void find_sol(){
        for(int i=0;i<R/2-1;i++){
            if((R/2-i-2)*i==B){
                std::cout << R/2-i <<' ' << i+2  <<'\n';
                return ;
            }
        }
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    tile tl;
    tl.find_sol();

    return 0;
}