#include <iostream>
#include <vector>
using namespace std;
class change{
private:
    string str;
public:
    change(){
        std::cin >> str;
    }
    void find_sol(){
        int sol=0;
        for(int i=0;i<str.size();i++){
            if(str[i]!=str[0]){
                sol++;
                while(str[i]==str[i+1]){
                    i++;
                }
            }
        }
        std::cout << sol <<"\n";
    }

};
int main(){
    change cg;
    cg.find_sol();
    
    return 0;
}