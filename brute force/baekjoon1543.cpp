#include <iostream>
#include <vector>
using namespace std;
class searching{
private:
    string TEXT;
    string str;
public:
    searching(){
        getline(cin,TEXT);
        getline(cin,str);
    }
    void find_sol(){
        int sol=0;
        for(int i=0;i<TEXT.size();i++){
            if(TEXT.substr(i,str.size())==str){
                sol++;
                i+=str.size()-1;
            }
        }
        std::cout << sol<<'\n';

    }

};
int main(){
    searching sch;
    sch.find_sol();   
    return 0;
}