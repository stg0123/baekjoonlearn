#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
class bi_saerch{
private:
    ll N;
public:
    bi_saerch(){
        std::cin >>N;
    }
    void find_sol(){
        ll left =1,right=250000;
        ll mid;
        ll tmp;
        while(left<=right){
            mid=(left+right)/2;
            tmp=mid*(mid+1)/2;
            if(tmp==N){
                std::cout << mid;
                return ;
            }
            else if(tmp<N)
                left=mid+1;
            else
                right=mid-1;
        }
        std::cout << min(left,right);
    }


};
int main(){
    bi_saerch bs;
    bs.find_sol();

    return 0;
}