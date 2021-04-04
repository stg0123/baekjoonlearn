#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int tmp=0;
    for(int i=0;i<str.size();i++){
        if(tmp==0&&str[i]=='U')
            tmp++;
        else if(tmp==1&&str[i]=='C')
            tmp++;
        else if(tmp==2&&str[i]=='P')
            tmp++;
        else if(tmp==3&&str[i]=='C')
            tmp++;
    }
    if(tmp==4)
        std::cout << "I love UCPC";
    else
        std::cout <<"I hate UCPC";

    return 0;
}