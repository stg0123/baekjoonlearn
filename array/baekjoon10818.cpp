#include <iostream>

using namespace std;
int main(){
    int n,max=-1000000,min=1000000;
    std::cin >> n;
    int a[n]={};
    for (int i=0;i<n;i++){
        std::cin >> a[i];
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min=a[i];
    }
    std::cout << min << ' '<< max;
    return 0;

}