#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
class card{
private:
    unordered_map<ll,int> Maps;
    int N;
public:
    card(){
        std::cin >>N;
    }
    void find_sol(){
        int MAX=0;
        ll sol,tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            Maps[tmp]++;
            if(Maps[tmp]>MAX){
                MAX=Maps[tmp];
                sol=tmp;
            }
            else if(Maps[tmp]==MAX)
                sol=min(tmp,sol);
        }
        std::cout << sol<<'\n';
    }
};
int main(){
    card c1;
    c1.find_sol();
    return 0;
}