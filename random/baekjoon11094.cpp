#include <iostream>
#include <string>
using namespace std;
class simon{
public:
    simon(){
        string str1,str;
        std::cin >> str1;
        if(str1 !="Simon"){
            getline(cin,str1);
            return ;
        }
        std::cin >> str1;
        getline(cin,str);
        if(str1 == "says")
            std::cout << str<<'\n';
    }
};
int main(){
    int n;
    std::cin >> n;
    cin.ignore();
    for(int i=0;i<n;i++){
        simon s;
    }


    return 0;
}