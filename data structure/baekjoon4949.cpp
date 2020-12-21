#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
int main(){
    while(1){
        string str;
        getline(cin,str);
        if(str==".")
            break;
        stack<int> st1;
        bool flag =false;
        for(int i=0;i<str.length();i++){
            if(str[i]=='(')
                st1.push(1);
            else if(str[i]=='[')
                st1.push(2);
            else if(str[i]==')'){
                if(st1.empty()||st1.top()!=1){
                    std::cout << "no\n";
                    flag= true;
                    break;
                }
                else
                    st1.pop();
            }
            else if(str[i]==']'){
                if(st1.empty()||st1.top()!=2){
                    std::cout << "no\n";
                    flag= true;
                    break;
                }
                else
                    st1.pop();
            }
        }
        if(!flag){
            if(st1.empty())
                std::cout << "yes\n";
            else
                std::cout << "no\n";
        }
    }

    return 0;
}