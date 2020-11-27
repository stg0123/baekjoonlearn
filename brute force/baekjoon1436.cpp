#include <iostream>
#include <string>
using namespace std;
int main(){

    int n,count=0,s_ct=0;
    long long num=665;
    std::cin >> n;
    string str;
    while(count!=n){
        num++;
        s_ct=0;
        str=std::to_string(num);
        for(int i=0;i<str.length();i++){
            if(str[i]=='6')
                s_ct++;
            else
                s_ct=0;
            if(s_ct==3){
                count++;
                break;
            }
        }
        str.clear();
    }
    std::cout <<num;;

    return 0;
}