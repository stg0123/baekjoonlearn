#include <iostream>
using namespace std;
int main(){
    int n,sol=0,sum,max=0;
    string tmp,max_name;
    std::cin >> n;
    int a,b;
    for(int i=0;i<n;i++){
        std::cin >> tmp;
        std::cin >> a >>b;
        sum=0;
        while(b>=a){
            sum+=b/a;
            b=b%a+b/a*2;
        }
        sol+=sum;
        if(max<sum){
            max=sum;
            max_name=tmp;
        }
    }
    std::cout << sol << '\n'<<max_name<<'\n';

    return 0;
}