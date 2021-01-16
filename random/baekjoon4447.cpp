#include <iostream>
#include <vector>
#include <string>
using namespace std;
class goodbad{
private:
    string str;
public:
    goodbad(){
        getline(cin,str,'\n');
    }
    void find(){
        int g_cnt=0,b_cnt=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='G'||str[i]=='g')
                g_cnt++;
            else if(str[i]=='B'||str[i]=='b')
                b_cnt++;
        }
        if(g_cnt==b_cnt)
            std::cout << str << " is NEUTRAL\n";
        else if(g_cnt>b_cnt)
            std::cout << str << " is GOOD\n";
        else if(g_cnt<b_cnt)
            std::cout << str << " is A BADDY\n";
    }
};
int main(){
    int n;
    std::cin >> n;
    cin.ignore();
    for(int i=0;i<n;i++){
        goodbad gd;
        gd.find();
    }

    return 0;
}