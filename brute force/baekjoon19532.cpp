#include <iostream>
#include <vector>
using namespace std;
class mathing{
private:
    vector<int> val;
public:
    mathing(){
        val.resize(6);
        for(int i=0;i<6;i++)
            std::cin >> val[i];
    }
    void find_sol(){
        for(int i=-999;i<1000;i++){
            for(int j=-999;j<1000;j++){
                if(val[0]*i+val[1]*j==val[2] && val[3]*i+val[4]*j==val[5]){
                    std::cout << i << ' ' << j << '\n';
                    return ;
                }
            }
        }

    }


};
int main(){
    mathing mt;
    mt.find_sol();

    return 0;
}