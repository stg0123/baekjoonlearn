#include <iostream>
#include <string>
using namespace std;
int main(){
    std::string str;
    std::cin >>str;
    int ms_sum=0,ps_sum=0,tmp,flag=0;
    size_t idx=0;
    if(str[0]=='-'){
        for(int i=1;i<str.length();i++){
            if(str[i]=='-'||str[i]=='+'){
                ms_sum+=stoi(&str[idx+1]);
                idx=i;
            }
        }
        ms_sum+=stoi(&str[idx+1]);
        std::cout << -ms_sum;
    }
    else{
        idx--;
        for(int i=0;i<str.length();i++){
            if(flag==0){
                if(str[i]=='+'){
                    ps_sum+=stoi(&str[idx+1]);
                    idx=i;
                }
                else if(str[i]=='-'){
                    ps_sum+=stoi(&str[idx+1]);
                    flag=1;
                    idx=i;
                }
            }
            else if(str[i]=='-'||str[i]=='+'){
                ms_sum+=stoi(&str[idx+1]);
                idx=i;
            }
        }
        if(flag==0)
            ps_sum+=stoi(&str[idx+1]);
        else
            ms_sum+=stoi(&str[idx+1]);
        std::cout << ps_sum-ms_sum;       
    }
    return 0;
}