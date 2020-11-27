#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n,tmp=1,sum=0,j=0;
    std::cin >> n;
    std::string str;
    for (int i=0; i<n ;i++){
        std::cin >> str;
        while(1){
            if(str[j]=='O'){
               sum +=tmp; 
               tmp++;
            }
            else
                tmp=1;
            j++;
            if(str[j]=='\0')
                break;
        }
        std::cout << sum << '\n';
        tmp=1;
        sum=0;
        j=0;
        str={};
    }

        
    return 0;
}