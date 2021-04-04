#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class gcd_lcm{
private:
    vector<int> val;
    int N;
public:
    gcd_lcm(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int a,b;
        int tmp;
        ll s1,s2=1;
        for(int i=0;i<N;i++){
            std::cin >> a>>b;
            tmp=gcd(a,b);
            s2=lcm(s2,b/tmp);
            if(i==0)
                s1= a/tmp;
            else
                s1=gcd(s1,a/tmp);
        }
        std::cout << s1 << ' ' << s2 ;

    }
    ll gcd(ll n,ll m){
        m=m%n;
        if(m==0)
            return n;
        else
            return gcd(m,n);
    }
    ll lcm(ll a,ll b){
        return a*b/gcd(a,b);
    }



};
int main(){
    gcd_lcm gl;
    return 0;
}