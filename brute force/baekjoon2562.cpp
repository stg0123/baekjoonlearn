#include <iostream>

using namespace std;
int main(){
    int max=-1000000,count=0;
    int a[9]={};
    for (int i=0;i<9;i++){
        std::cin >> a[i];
        if(a[i]>max){
            max=a[i];
            count=i+1;
        }
    }
    std::cout << max << '\n'<< count;
    return 0;

}