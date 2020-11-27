#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
string reverse(string str){
    char a[str.length()]={};
    for(int i=0;i<str.length();i++)
        a[i]=str[str.length()-(i+1)];

    return a;

}

int main(){
    std::string str1,str2;
    std::cin >>str1 >>str2;
    str1=reverse(str1);
    str2=reverse(str2);
    int a,b;
    a=std::stoi(str1);
    b=std::stoi(str2);
    if(a>b)
        std::cout << a;
    else
        std::cout << b;
    
    
    return 0;

}