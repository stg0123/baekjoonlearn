#include <iostream>
#include <vector>
using namespace std;
class mountain{
private:
    int L,P,V;
public:
    mountain(int l,int p,int v):L(l),P(p),V(v){
    }
    void find_sol(){
        int sol=0;
        sol=(V/P)*L+(V%P>L? L : V%P);
        std::cout << sol <<'\n';
    }

};
int main(){
    int l,p,v;
    int i=0;
    while(1){
        i++;
        std::cin >> l >> p >> v;
        if(l==0 &&p==0 &&v==0)
            break;
        mountain m(l,p,v);
        std::cout << "Case " << i <<": ";
        m.find_sol();
    }
    return 0;
}