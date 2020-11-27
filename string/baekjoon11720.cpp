#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
int main(){
    std::string str;
    int sum=0,n;
    std::cin >> n;
    std::cin >> str;
    for(int i=0;i<n;i++)
        sum +=str[i]-'0';
    std::cout << sum;


    return 0;
}