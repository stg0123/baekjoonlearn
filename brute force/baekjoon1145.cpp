#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int INF=1000000000;
class gcdlcm{
private:
    vector<int> val;
public:
    gcdlcm(){
        val.resize(5);
        set_val();
    }
    void set_val(){
        for(int i=0;i<5;i++)
            std::cin >> val[i];
    }
    int gcd(int a,int b){
        return b ? gcd(b,a%b) : a;
    }
    void find_sol(){
        int sol=INF;
        vector<bool> select(5,false);
        for(int i=0;i<3;i++)
            select[i]=true;
        do{
            int last=0;
            for(int i=0;i<5;i++){
                if(select[i]){
                    if(last)
                        last=last*val[i]/gcd(last,val[i]);
                    else
                        last=val[i];
                }
            }
            sol=min(sol,last);
        }while(prev_permutation(select.begin(),select.end()));
        std::cout<< sol << '\n';
    }   

};
int main(){
    gcdlcm gl;
    gl.find_sol();
    return 0;
}