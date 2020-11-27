#include <iostream>

using namespace std;
int factorial(int a){
    if(a<=1)
        return 1;
    else 
        return factorial(a-1)*a;

};
int main(){
    int n;
    std::cin >> n;
    std::cout<< factorial(n);
    


    return 0;
}