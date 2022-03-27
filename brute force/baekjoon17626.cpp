#include <iostream>
#include <vector>
using namespace std;
class squares{
private:
    int N;
public:
    squares(){
        std::cin >> N;
    }
    void find_sol(){
        int i=0,j=0,k=0;
        while(1){
            j=i;
            while(1){
                k=j;
                while(1){
                    int tmp = i*i+j*j+k*k;
                    if(tmp==N){
                        if(i==0 && j==0)
                            std::cout << 1 << '\n';
                        else if(i==0)
                            std::cout << 2 << '\n';
                        else
                            std::cout << 3 << '\n';
                        return ;
                    }
                    else if(tmp>N)
                        break; 
                    k++;
                }
                j++;
                if(i*i+j*j*2>N)
                    break ;
            }
            i++;
            if(i*i*3>N)
                break ;
        }
        std::cout << 4 << '\n';
    }

};
int main(){
    squares sq;
    sq.find_sol();
    return 0;
}