#include <iostream>
#include <algorithm>
using namespace std;

class password{
private:
    string st1,st2;
    string str;
public:
    password(){
        std::cin >> str;
    }
    void find_sol(){
        for(int i=0;i<str.length();i++){
            if(str[i]=='<'){
                if(!st1.empty()){
                    st2.push_back(st1.back());
                    st1.pop_back();
                }
            }
            else if(str[i]=='>'){
                if(!st2.empty()){
                    st1.push_back(st2.back());
                    st2.pop_back();
                }
            }
            else if(str[i]=='-'){
                if(!st1.empty())
                    st1.pop_back();
            }
            else{
                st1.push_back(str[i]);
            }
        }
        reverse(st2.begin(),st2.end());
        std::cout << st1<<st2 <<'\n';
    }
};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        password p1;
        p1.find_sol();
    }
    return 0;
}