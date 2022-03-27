#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n,max=0;
    float avg=0;
    std::cin >> n;
    int grade[n]={};
    for(int i=0;i<n;i++){
        std::cin >> grade[i];
        if(grade[i]>max)
            max=grade[i]; 
    }
    for(int i=0;i<n;i++)
        avg += (float)grade[i]/max*100;
    printf("%.2f",avg/n);
        
    return 0;
}