#include <iostream>
using namespace std;
class binary_{
private:
    int N;
public:
    binary_(){
        std::cin >> N;
    }
    void find(){
        int n=0;
        while(N>0){
            if(N%2==1)
                std::cout << n <<' ';
            N/=2;
            n++;
        }
        std::cout << '\n';
    }

};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        binary_ bi;
        bi.find();
    }

    return 0;
}