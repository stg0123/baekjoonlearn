#include <iostream>
using namespace std;
class gcdlcm{
private:
    int N;
public:
    gcdlcm(){
        std::cin >> N;
    }
    int gcd(int a,int b){
        return b ? gcd(b,a%b) : a;
    }
    void find_sol(){
        int a,b;
        for(int i=0;i<N;i++){
            std::cin >> a >> b;
            int tmp = gcd(a,b);
            std::cout << a*b/tmp <<' ' << tmp << '\n';
        }
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    gcdlcm gl;
    gl.find_sol();
    

    return 0;
}