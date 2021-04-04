#include <iostream>
using namespace std;
class stick{
private:
    string str;
public:
    stick(){
        std::cin >> str;
    }
    void find_sol(){
        int sol=0;
        int idx=0;
        char last;
        for(int i=0;i<str.size();i++){
            if(str[i]=='(')
                idx++;
            else{
                idx--;
                if(last==')')
                    sol++;
                else
                    sol+=idx;
            }
            last=str[i];
        }
        std::cout << sol;

    }
};
int main(){
    stick sk;
    sk.find_sol();


    return 0;
}