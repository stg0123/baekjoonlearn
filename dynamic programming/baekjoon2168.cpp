#include <iostream>
#include <vector>
using namespace std;
class tile{
private:
    int N,M;
public:
    tile(){
        std::cin >> N >> M;
    }
    int gcd(int n,int m){
        m=m%n;
        if(m==0)
            return n;
        else 
            return gcd(m,n);
    }
    void find_sol(){
        int tmp= gcd(N,M);
        int n=N/tmp,m=M/tmp;
        int sol= (n+m-1)*tmp;
        std::cout << sol << '\n';

    }

};
int main(){
    tile ti;
    ti.find_sol();
    return 0;
}