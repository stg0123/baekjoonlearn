#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
int main(){
    int al[26],n;
    for(int i=0;i<26;i++)
        al[i]=-1;
    std::string str;
    std::cin >> str;
    
    for(int i=0; i<str.length();i++)
        if(al[str[i]-97]==-1)
            al[str[i]-97]=i;

    for(int i=0;i<26;i++)
        std::cout <<al[i] << ' ';
        

    return 0;
}