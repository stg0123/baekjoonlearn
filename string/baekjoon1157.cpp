#include <iostream>
#include <string>
using namespace std;
int main(){
    int  a[26]={},max=0,f=0;
    char maxchar;
    std::string str;
    std::cin >>str;
    for(int i=0;i<str.length();i++)
        if(str[i]>=97)
            a[str[i]-97]++;
        else
            a[str[i]-65]++;
    for(int i=0;i<26;i++)
        if(a[i]>max){
            maxchar =i+65;
            max=a[i];
        }
    for(int i=0;i<26;i++)
        if(a[i]==max)
            f++;

    if(f>=2)
        maxchar = '?';
    std::cout << maxchar;        
    
    return 0;   

}