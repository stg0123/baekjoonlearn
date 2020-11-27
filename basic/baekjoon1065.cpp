#include <iostream>
#include <string>

using namespace std;
bool han_num(int n){
    if(n<100)
        return true;
    int mod=10;
    int d=n%10-(n%100)/10,tmp=n%mod;
    std::string str = std::to_string(n);
    for(int i=1;i<str.length();i++){
        mod *=10;
        if(tmp-(n%mod)/(mod/10)==d)
            tmp=(n%mod)/(mod/10);
        else
            return false;
    }
    return true;
}

int main(){
    int n,count=0;
    std::cin >> n;
    for(int i=1;i<=n;i++)
        if(han_num(i))
            count++;
    std::cout<< count;

    return 0;
}