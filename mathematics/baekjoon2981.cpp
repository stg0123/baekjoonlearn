#include <iostream>
#include <vector>
using namespace std;
class Euclid{
private:
    vector<int> map;
    int N;
public:
    Euclid(int n):N(n){

    };
    int gcd(int n,int m){
        n=n%m;
        if(n==0)
            return m;
        else
            return gcd(m,n);
    };
    void set_val(){
        int a,tmp=0;
        std::cin >> tmp;
        for(int i=0;i<N-1;i++){
            std::cin >> a;
            map.push_back(abs(tmp-a));
            tmp=a;
        }
    };

    int find(){
        int tmp=map[0];
        for(int i=1;i<map.size();i++)
            tmp=gcd(tmp,map[i]);
        return tmp;
    }
    
    void find_divisor(int n){
        if(n%2==0){
            for(int i=2;i<=n/2;i++)
                if(n%i==0)
                    std::cout << i << ' ';
        }
        else{
            int a=1;
            for(int i=3;i<=n;i++)
                if(n%i==0){
                   a=i;
                   break;
                }
            for(int i=a;i<=n/a;i++)
                if(n%i==0)
                    std::cout << i << ' ';
        }
        std::cout << n << '\n';
    }
    
    
};
int main(){
    int n;
    std::cin >> n;
    Euclid Eu(n);
    Eu.set_val();
    Eu.find_divisor(Eu.find());

    return 0;
}