#include <iostream>
#include <vector>
using namespace std;
class tonerment{
private:
    int N,A,B;
public:
    tonerment(){
        std::cin >> N >> A >> B;
    }
    void find_sol(){
        int sol =1;
        while(1){
            A=(A+1)/2;
            B=(B+1)/2;
            if(A==B)
                break;
            sol++;
        }
        std::cout << sol <<'\n';
    }

};
int main(){
    tonerment tt;
    tt.find_sol();

    return 0;
}