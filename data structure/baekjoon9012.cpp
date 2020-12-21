#include <iostream>
#include <stack>

using namespace std;
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        stack<int> st;
        string str;
        std::cin >> str;
        bool flag =false;
        for(int j=0;j<str.length();j++){
            if(str[j]=='(')
                st.push(1);
            else if(str[j]==')'){
                if(st.empty()){
                    std::cout << "NO\n";
                    flag=true;
                    break;
                }
                st.pop();
            }
        }
        if(!flag){
            if(st.empty())
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
    }

    return 0;
}