#include <iostream>


using namespace std;
int main(){
    int n,tmp;
    bool flag=false;
    std::cin >> n;
    int sum=n/3;
    for(int i=0;i<=n/5;i++){
        tmp=n-5*i;
        if(tmp%3==0&&i+tmp/3<=sum){
                flag=true;
                sum=i+tmp/3;
        }
    }
    if(flag)
        std::cout << sum;
    else
        std::cout <<-1;
    
    
    return 0;
}