#include <iostream>
#include <string>

using namespace std;
string repeat(string str,int k){
    int n=str.length();
    char a[n*k+1]={};
   // std::cout << "\n!" << str << " n="<<n<< " k="<<k << "!\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            a[j+(i*k)]=str[i];
    a[n*k]='\0';
    return a;

}

int main(){
    int n,k;
    std::string str;
    std::cin >>n;
    for(int i=0;i<n;i++){
        std::cin >>k >>str;
        std::string a=repeat(str,k);
        std::cout << a <<'\n';
    }
    return 0;

}