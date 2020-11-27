#include <iostream>
#include <string>

using namespace std;
int main(){
    std::string str;
    std::cin >>str;
    int sum=0,a=0;
    for(int i=0;i<str.length();i++){
        if(str[i]<83)
            a=(str[i]-65)/3+2;
        else if(str[i]==83)
            a=7;
        else if(str[i]>83&&str[i]<=86)
            a=8;
        else if(str[i]>86&&str[i]<=90)
            a=9;
            
        sum+=(a+1);
    }
    std::cout <<sum;
    


    return 0;
}