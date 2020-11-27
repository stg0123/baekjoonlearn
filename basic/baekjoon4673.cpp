#include <iostream>
#include <string>

using namespace std;
int d(int n){
    int mod=10,sum=0;
    std::string str = std::to_string(n);
    for(int i=0;i<str.length();i++){
        sum+=(int)(n%mod)/(mod/10);
        mod*=10;
    }   
    return sum+n;
};
int main(){
    bool map[10001]={};
    for(int i=1;i<=10000;i++){
        if(d(i)>10000)
            continue;
        map[d(i)]=true;
    }
    for(int i=1;i<=10000;i++)
        if(map[i]==false)
            std::cout << i << '\n';
    
    return 0;
}