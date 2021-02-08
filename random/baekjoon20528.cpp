#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    string str;
    char ch;
    std::cin >> n;
    std::cin >> str;
    ch=str[0];
    bool flag=true;
    for(int i=0;i<n-1;i++){
        std::cin >> str;
        if(ch!=str[0])
            flag=false;
    }
    if(flag)
        std::cout <<1;
    else
        std::cout << 0;


    return 0;
}