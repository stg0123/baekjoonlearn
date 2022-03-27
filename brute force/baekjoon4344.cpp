#include <iostream>
#include <cstdio>

using namespace std;
int main(){
    int C,n;
    std::cin >> C;
    for(int i=0;i<C;i++){
        std::cin >> n;
        int grade[n]={};
        int tmp=0,count=0;
        double avg=0;
        for(int j=0;j<n;j++){
            std::cin >> grade[j];
            tmp+=grade[j];
        }
        avg=(double)tmp/n;
        for(int j=0;j<n;j++)
            if(grade[j]>avg)
                count++;
        printf("%.3lf%%\n",(double)count/n*100);

    }


    return 0;
}