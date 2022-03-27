#include <iostream>
#include <vector>
using namespace std;
class tiger{
private:
    vector<int> val;
    int D,K;
public:
    tiger(){
        std::cin >> D >> K;
        val.resize(D+1);
    }
    void find_sol(){
        val[1]=1;
        while(1){
            val[2]=val[1];
            while(1){
                for(int i=3;i<=D;i++)
                    val[i]=val[i-1]+val[i-2];
                if(val[D]==K){
                    std::cout << val[1]<<'\n';
                    std::cout << val[2]<<'\n';
                    return ;
                }
                else if(val[D]>K)
                    break;
                val[2]++;
            }
            val[1]++;
        }
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    tiger tg;
    tg.find_sol();   

    return 0;
}