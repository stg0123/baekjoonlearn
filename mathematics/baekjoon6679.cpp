#include <iostream>
#include <vector>
using namespace std;
class finding{
public:
    finding(){
    }
    int find_n(int cur,int n){
        int sol=0;
        while(cur){
            sol+=cur%n;
            cur/=n;
        }
        return sol;
    }

    void find_sol(){
        for(int val=1000;val<10000;val++){
            int tmp = (val%10)+((val/10)%10)+((val/100)%10)+(val/1000);
            if(tmp == find_n(val,12) && tmp == find_n(val,16))
                std::cout << val << '\n';
        }
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    finding fd;
    fd.find_sol();
    return 0;
}