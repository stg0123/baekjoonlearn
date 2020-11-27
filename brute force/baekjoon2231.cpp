#include <iostream>
#include <string>
using namespace std;
int div_sum(int n){
    std::string str=std::to_string(n);
    int mod=10,sum=0;
    for(int i=0;i<str.length();i++){
        sum += (n%mod)/(mod/10);
        mod *=10;
    }
    return sum+n;

}

int main(){
    int n,sol=0;
    std::cin >> n;
    for(int i=0;i<n;i++)
        if(div_sum(i)==n){
            sol=i;
            break;
        }

    std::cout << sol;
    return 0;
            
}