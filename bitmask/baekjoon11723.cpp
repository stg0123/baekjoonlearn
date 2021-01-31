#include <iostream>
#include <vector>
using namespace std;
class bit_mask{
private:
    int bit;
public:
    bit_mask(){
        bit=0;
    }    
    void oper(){
        string str;
        std::cin >>str;
        int n;
        if(str=="add"){
            std::cin >> n;
            bit |= (1<<n);
        }
        else if(str=="remove"){
            std::cin >> n;
            bit &=~(1<<n);
        }
        else if(str=="check"){
            std::cin >> n;
            if(bit&(1<<n))
                std::cout << 1 <<'\n';
            else
                std::cout << 0 << '\n';
        }
        else if(str=="toggle"){
            std::cin >> n;
            bit ^=(1<<n);
        }
        else if(str=="all"){
            bit |=(1<<21)-1;
        }
        else if(str=="empty"){
            bit=0;
        }
    }


};
int main(){
    bit_mask bm;
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        bm.oper();
    }
    

    return 0;
}