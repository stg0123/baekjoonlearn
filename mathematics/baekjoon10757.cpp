#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    vector<int> num1,num2;
    vector<int> sol;
    string str;
    std::cin >>str;
    for(int i=0;i<str.size();i++)
        num1.push_back(str[i]-48);
    std::cin >> str;
    for(int i=0;i<str.size();i++)
        num2.push_back(str[i]-48);
        
    int tmp=0,num1_e,num2_e;
    int sum;
    while(1){
        if(num1.empty()&&num2.empty())
            break;
        if(num1.empty())
            num1_e=0;
        else{
            num1_e=num1.back();
            num1.pop_back();
        }

        if(num2.empty())
            num2_e=0;
        else{
            num2_e=num2.back();
            num2.pop_back();
        }
        sum=num1_e+num2_e+tmp;
        sol.push_back(sum%10);
        tmp=sum/10;
    }
    if(tmp!=0)
        std::cout << tmp;
    for(int i=sol.size()-1;i>=0;i--)
        std::cout <<sol[i];


    return 0;
}