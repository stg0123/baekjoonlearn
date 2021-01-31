#include <iostream>
using namespace std;
int main(){
    int n,sum=0,tmp;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> tmp;
        sum+=tmp;
    }
    if(n==0||sum==0)
        std::cout << "divide by zero";
    else
        printf("%.2f",1.00);
    
    return 0;
}