#include <iostream>

using namespace std;
int main(){
    int A,B,V,cnt=0,count=0;
    cin >>A>>B>>V;
    count=(V-A)/(A-B);
    cnt=count*(A-B);
    while(1){
        count++;
        cnt+=A;
        if(cnt>=V)
            break;
        cnt-=B;
    }


    std::cout <<count;



    return 0;
}