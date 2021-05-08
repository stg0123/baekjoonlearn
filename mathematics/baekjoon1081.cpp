#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
class suming{
private:
    ll A,B;
public:
    suming(){
        std::cin >> A >> B;
        std::cout << sum(B)-sum(A-1);
    }
    ll sum(ll n){
        if(n<=0)
            return 0;
        vector<ll> count(10,0);
        ll tmp=1,upcnt,curcnt;
        while(n>0){
            upcnt = n/(tmp*10);
            curcnt = n%(tmp*10);
            for(int i=0;i<10;i++)
                count[i]+=upcnt*tmp;
            for(int i=1;i<=curcnt/tmp;i++)
                count[i]+= tmp;
            count[(curcnt/tmp+1)%10] += curcnt%tmp;
            n-= 9*tmp;
            tmp*=10;
        }
        ll sum=0;
        for(int i=1;i<10;i++)
            sum+= i*count[i];
        return sum;
    }

};
int main(){
    suming si;
    return 0;
}
