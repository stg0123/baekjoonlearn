#include <iostream>
using namespace std;
class supermario{
private:
    int N=10,goal=100;
public:
    supermario(){
        
    }
    void find_sol(){
        int sum=0,a;
        bool flag=false;
        for(int i=0;i<N;i++){
            std::cin >> a;
            if(!flag){
                if(abs(sum-goal)>=abs(sum+a-goal))
                    sum+=a;
                else
                    flag=true;
            }
        }
        std::cout << sum << '\n';
    }

};
int main(){
    supermario sm;
    sm.find_sol();
    return 0;
}