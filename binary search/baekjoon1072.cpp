#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class game{
private:
    ll X,Y;
public:
    game(){
        std::cin >> X  >> Y;
    }
    void find_sol(){
        int cur =Y*100/X;
        if(cur>=99){
            std::cout << -1<<'\n' ;
            return ;
        }
        ll left=0,right=X,tmp,mid;
        while(left<=right){
            mid=(left+right)/2;
            tmp =(Y+mid)*100/(X+mid);
            if(cur<tmp)
                right=mid-1;
            else
                left=mid+1;
        }
        std::cout << left;
    }

};
int main(){
    game g;
    g.find_sol();
    return 0;
}