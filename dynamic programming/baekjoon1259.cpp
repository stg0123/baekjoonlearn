#include <iostream>
#include <vector>
using namespace std;
class pelindrom{
private:
    string str;
public:
    pelindrom(string s):str(s){
        if(find(0,str.size()-1))
            std::cout <<"yes\n";
        else
            std::cout << "no\n";
    }
    bool find(int start,int end){
        if(start>end)
            return true;
        if(str[start]==str[end]&&find(start+1,end-1))
            return true;
        return false;
    }


};
int main(){
    string str;
    while(1){
        std::cin >> str;
        if(str=="0")
            break;
        pelindrom p(str);
    }

    return 0;
}