#include <iostream>
#include <string>

using namespace std;
int main(){
    std::string str;
    getline(cin,str);
    int count=0;
    for(int i=0;i<str.length();i++)
        if(str[i]==' ')
            count++;
    if(str[0]==' ')
        count --;
    if(str[str.length()-1]==' ')
        count --;

    std::cout <<count+1;

    

    return 0;
}