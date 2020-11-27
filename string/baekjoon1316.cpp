#include <iostream>
#include <string>

using namespace std;
bool g_word(string str){
    bool a[26]={};
    char tmp=0;
    for(int i=0;i<str.length();i++){
        if(str[i]!=tmp){
            if(a[str[i]-97]==true)
                return false;
            else{
                a[str[i]-97]=true;
                tmp=str[i];
            }
        }
    }
    return true;
};

int main(){

    std::string str; 
    int n,count=0;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> str;
        count += g_word(str);
    }
    std::cout << count;

    return 0;

}