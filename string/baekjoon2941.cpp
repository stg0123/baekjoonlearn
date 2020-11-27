#include <iostream>
#include <string>

using namespace std;
int main(){
    std::string str;
    std::cin >> str;
    int n=str.length();
    for(int i=0;i<str.length()-1;i++){
        if(str[i]=='c'&&str[i+1]=='=')
            n--;
        else if(str[i]=='c'&&str[i+1]=='-')
            n--;
        else if(str[i]=='d'&&str[i+1]=='-')
            n--;
        else if(str[i]=='l'&&str[i+1]=='j')
            n--;
        else if(str[i]=='n'&&str[i+1]=='j')
            n--;
        else if(str[i]=='s'&&str[i+1]=='=')
            n--;
        else if(str[i]=='z'&&str[i+1]=='='){
            if(str[i-1]=='d')
                n--;
            n--;
        }

    } 
    std::cout <<n;
    return 0;
}