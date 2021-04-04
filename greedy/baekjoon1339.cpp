#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
bool compare(int a,int b){
    return a>b;
};
class words_math{
private:
    vector<int> alpha_val;
    int N;
public:
    words_math(){
        std::cin >> N;
        alpha_val.resize(26,0);
        set_val();
    }
    void set_val(){
        string str;
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >> str;
            tmp=round(pow(10,str.size()));
            for(int i=0;i<str.size();i++){
                tmp/=10;
                alpha_val[str[i]-'A']+=tmp;
            }
        }
        sort(alpha_val.begin(),alpha_val.end(),compare);
    }
    void find_sol(){
        ll sol=0,tmp=9;
        for(int i=0;i<9;i++){
            sol+=alpha_val[i]*(tmp--);
        }
        std::cout << sol;
    }
};
int main(){
    words_math wm;
    wm.find_sol();
    return 0;
}