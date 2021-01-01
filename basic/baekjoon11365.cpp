#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    while(1){
        getline(cin,str,'\n');
        if(str=="END")
            break;
        for(auto i=str.rbegin();i!=str.rend();i++)
            std::cout << *i;
        std::cout <<'\n';
    }
    return 0;
}