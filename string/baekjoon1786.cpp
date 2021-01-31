#include <iostream>
#include <vector>
#include <string>
using namespace std;
class KMP_basic{
private:
    string TEXT;
    string str;
    vector<int> pi;
    vector<int> sol;
public:
    KMP_basic(){
        getline(cin,TEXT);
        getline(cin,str);
        getpi();
    }
    void getpi(){
        pi.resize(str.length(),0);
        for(int i=1,j=0;i<str.length();i++){
            while(j>0&& str[i]!=str[j])
                j=pi[j-1];
            if(str[i]==str[j])
                pi[i]=++j;
        }
    }
    void KMP(){
        for(int i=0,j=0;i<TEXT.length();i++){
            while(j>0&&TEXT[i]!=str[j])
                j=pi[j-1];
            if(TEXT[i]==str[j]){
                if(j==str.length()-1){
                    sol.push_back(i-str.length()+1);
                    j=pi[j];
                }
                else
                    j++;
            }
        }
    }
    void print_sol(){
        std::cout << sol.size()<<'\n';
        for(int i=0;i<sol.size();i++)
            std::cout << sol[i]+1 << ' ';
    }
};
int main(){
    KMP_basic kb;
    kb.KMP();
    kb.print_sol();

    return 0;
}