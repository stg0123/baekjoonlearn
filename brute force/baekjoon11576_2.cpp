#include <iostream>
using namespace std;
class conversion{
private:
    int A,B;
public:
    conversion(){
        std::cin >>A >>B;
    }
    void number(int n){
        if(n==0)
            return ;
        number(n/B);
        std::cout << n%B<<' ';
    }
    void find_sol(){
        int n,sol=0;
        std::cin >> n;
        for(int i=0;i<n;i++){
            int tmp;
            std::cin >> tmp;
            sol= sol*A +tmp;
        }
        number(sol);
    }

};
int main(){
    conversion cs;
    cs.find_sol();
    return 0;
}