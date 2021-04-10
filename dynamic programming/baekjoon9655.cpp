#include <iostream>
#include <vector>
using namespace std;
class stone{
private:
    int N;
public:
    stone(){
        std::cin >> N;
        if(N%2)
            std::cout << "SK";
        else
            std::cout << "CY";
    }
    
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    stone st;
    return 0;
}