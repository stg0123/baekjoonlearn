#include <iostream>
#include <vector>
using namespace std;
class stick{
private:
    int X;
public:
    stick(){
        std::cin >> X;
    }
    void find_sol(){
        int sol=0;
        for(int i=0;i<=6;i++){
            sol+=X&1;
            X>>=1;
        }
        std::cout << sol <<'\n';
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    stick sk;
    sk.find_sol();
    return 0;
}