#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class page{
private:
    ll N;
    vector<int> count; 
public:
    page(){
        std::cin >> N;
        count.resize(10,0);
    }
    void find_sol(){
        int upcnt,curcnt,tmp=1;
        while(N>0){
            upcnt = N/(tmp*10);
            curcnt = N%(tmp*10);
            for(int i=0;i<10;i++)   
                count[i] += upcnt*tmp;
            for(int i=1;i<=curcnt/tmp;i++)
                count[i] += tmp;
            count[(curcnt/tmp+1)%10] += curcnt % tmp;
            N -= 9 *tmp;
            tmp*=10;
        }
        for(int i=0;i<10;i++)
            std::cout << count[i] << ' ';
    }

};
int main(){
    page pg;
    pg.find_sol();
    return 0;
}