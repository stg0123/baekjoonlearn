#include <iostream>

using namespace std;
int fibonachi(int a){
    if(a==0)
        return 0;
    else if(a==1)
        return 1;
    else 
        return fibonachi(a-1)+fibonachi(a-2);

};
int main(){
    int n;
    std::cin >> n;
    std::cout<< fibonachi(n);
    


    return 0;
}