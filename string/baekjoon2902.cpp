#include <iostream>
#include <vector>
using namespace std;
int main(){
    string str;
    string sol;
    std::cin >> str;
    for(int i=0;i<str.size();i++){
        if(str[i]>='A' && str[i]<='Z')
            sol.push_back(str[i]);
    }
    std::cout << sol;

    return 0;
}