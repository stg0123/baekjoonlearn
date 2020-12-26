#include <iostream>
#include <vector>
using namespace std;
class ring{
private:
    vector<int> map;
    int N;
public:
    ring(int n):N(n){

    };
    void set_val(){
        int a;
        for(int i=0;i<N;i++){
            std::cin >> a;
            map.push_back(a);
        }
    }
    int gcd(int a,int b){
        a=a%b;
        if(a==0)
            return b;
        else
            return gcd(b,a);
    };

    void round(){
        int g=0;
        for(int i=1;i<N;i++){
            g=gcd(map[0],map[i]);
            std::cout << map[0]/g << '/'<<map[i]/g<<'\n';
        }
    };
    

};
int main(){
    int n;
    std::cin >>n;
    ring r(n);
    r.set_val();
    r.round();
    return 0;
    
}