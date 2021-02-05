#include <iostream>
using namespace std;
int main(){
    int last,cur;
    bool flag=true,flag2=true;
    std::cin >> last;
    if(last==8)
        flag=false;
    for(int i=0;i<7;i++){
        std::cin>> cur;
        if(flag){
            if(cur==last+1)
                last =cur;
            else
                flag2=false;
        }
        else{
            if(cur==last-1)
                last=cur;
            else
                flag2=false;
        }
    }
    if(flag2==false)
        std::cout<<"mixed";
    else if(flag==true)
        std::cout<<"ascending";
    else
        std::cout<<"descending";

    return 0;
}