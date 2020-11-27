#include <iostream>
#include <string>
using namespace std;
int main(){
    long long a,b,c,sum,mod=10,tmp=0;
    int x[10]={};
    std::cin >> a >> b >> c;
    sum=a*b*c;
    std::string str = std::to_string(sum);

    for(int i=0;i<str.length();i++){
        x[(sum%mod-tmp)/(mod/10)]++;
        tmp=sum%mod;
        mod *=10;
    }
    for(int i=0;i<10;i++)
        std::cout << x[i] << '\n';
    return 0;

}