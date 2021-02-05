#include <iostream>
#include <vector>
#include <string>
using namespace std;
class string_pow{
private:
    string str;
    vector<int> pi;
public:
    string_pow(string s):str(s){
        getpi();
    }
    void getpi(){
        pi.resize(str.length(),0);
        for(int i=1,j=0;i<str.length();i++){
            while(j>0&&str[i]!=str[j])
                j=pi[j-1];
            if(str[i]==str[j])
                pi[i]=++j;
        }
        int tmp =str.length()-pi[str.length()-1];
        if(str.length()%tmp)
            std::cout<< 1 << '\n';
        else
            std::cout << str.length()/tmp<<'\n';
    }
};
int main(){
    string str;
    while(1){
        std::cin >> str;
        if(str ==".")
            break;
        string_pow s(str);
    }

    return 0;
}