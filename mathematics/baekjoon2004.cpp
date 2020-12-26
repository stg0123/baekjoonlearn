#include <iostream>
#include <vector>
using namespace std;
class element_num{
private:
    int A,B;
public :
    element_num(int a,int b):A(a),B(b){
        
    };

    int two(int n){
        int sum=0;
        while(n>=2){
            sum+=n/2;
            n/=2;
        }
        return sum;
    };
    
    int five(int n){
        int sum=0;
        while(n>=5){
            sum+=n/5;
            n/=5;
        }
        return sum;
    };

    void sol(){
        int twos=0,fives;
        twos+=two(A);
        twos-=two(B);
        twos-=two(A-B);

        fives+=five(A);
        fives-=five(B);
        fives-=five(A-B);

        std::cout << min(twos,fives);
    
    }

};
int main(){
    int a,b;
    std::cin >>a >>b;
    element_num el(a,b);
    el.sol();
    
    return 0;
}