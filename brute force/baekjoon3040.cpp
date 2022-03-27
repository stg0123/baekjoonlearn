#include <iostream>
#include <vector>
using namespace std;
class princess{
private:
    vector<int> val;
    int sum=0;
public:
    princess(){
        val.resize(9);
        set_val();
    }
    void set_val(){
        for(int i=0;i<9;i++){
            std::cin >> val[i];
            sum +=val[i];
        }
    }
    void find_sol(){
        for(int i=0;i<8;i++){
            for(int j=i+1;j<9;j++){
                if((sum-val[i]-val[j])==100){
                    for(int l=0;l<9;l++){
                        if(l!=i &&l!=j)
                            std::cout << val[l]<<'\n';
                    }
                }
            }
        }
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    princess pc;
    pc.find_sol();
    return 0;
}