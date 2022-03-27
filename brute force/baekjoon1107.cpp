#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class remote{
private:
    vector<int> button;
    int N;
public:
    remote(){
        std::cin >>N;
        button.resize(10,0);
        set_val();
    }   
    void set_val(){
        int n,tmp;
        std::cin >> n;
        for(int i=0;i<n;i++){
            std::cin >> tmp;
            button[tmp]++;
        }
    }
    void find_sol(){
        int m=abs(N-100);
        int len,c;
        bool flag;
        for(int i=0;i<1000000;i++){
            flag=true;
            c=i;
            len=1;
            while(1){
                if(button[c%10])
                    flag=false;
                if(c/=10)
                    len++;
                else
                    break;
            }
            if(flag)
                m = min((abs(N-i))+len,m);
        }
        std::cout << m << '\n';
    }   
};

int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    remote rm;
    rm.find_sol();

    return 0;
}