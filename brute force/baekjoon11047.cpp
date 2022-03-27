#include <iostream>

using namespace std;
int main(){
    int n,k,tmp=-1,sum=0;
    std::cin >> n >> k;
    int a[n]={};
    for(int i =0;i<n;i++){
        std::cin >>a[i];
        if(a[i]>k)
            tmp=i;
    }
    if(tmp==-1){
        for(int i=1;i<=n;i++){
            sum +=k/a[n-i];
            k %=a[n-i];
            if(k==0)
                break;
        }
    }
    else{
        for(int i=tmp;i>=0;i--){
            sum+=k/a[i];
            k %=a[i];
            if(k==0)
                break;
        }
    }
    std::cout << sum;
    

    return 0;
}