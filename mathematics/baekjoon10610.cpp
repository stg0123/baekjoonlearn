#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string str;
    std::cin >> str;
    int sum=0;
    bool flag=false;
    for(int i=0;i<str.size();i++){
        sum+=(str[i]-'0');
        if(str[i]=='0')
            flag=true;
    }
    if(sum%3!=0 || !flag)
        std::cout << -1;
    else{
        sort(str.begin(),str.end());
        for(int i=str.size()-1;i>=0;i--)
            std::cout << str[i];
    }    

    return 0;
}