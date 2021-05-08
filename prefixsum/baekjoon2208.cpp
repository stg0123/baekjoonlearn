#include <iostream>
#include <vector>
using namespace std;
class jewel{
private:
    vector<int> sum;
    int N,M;
public:
    jewel(){
        std::cin >> N >>M;
        sum.resize(N+1,0);
    }
    void find_sol(){
        int sol=0,interval_min=0;
        int tmp;
        for(int i=1;i<=N;i++){
            std::cin >> tmp;
            sum[i]=sum[i-1]+tmp;
            if(i>=M){
                interval_min=min(sum[i-M],interval_min);
                sol=max(sol,sum[i]-interval_min);
            }
        }
        std::cout << sol ;
    }


};
int main(){
    jewel j;
    j.find_sol();
    return 0;
}