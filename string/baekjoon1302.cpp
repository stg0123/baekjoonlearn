#include <iostream>
#include <vector>
#include <map>
using namespace std;
class topbook{
private:
    map<string,int> m;
    int N;
public:
    topbook(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        string str;
        int sol=0;
        string sol_str;
        for(int i=0;i<N;i++){
            std::cin >> str;
            m[str]++;
            if(m[str]>sol){
                sol=m[str];
                sol_str=str;
            }
            else if(m[str]==sol && str < sol_str){
                sol_str=str;
            }
        }
        std::cout << sol_str;
    }
};
int main(){
    topbook tb;
    
    return 0;
}