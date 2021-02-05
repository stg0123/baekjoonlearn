#include <iostream>
#include <vector>
using namespace std;
class dq_pow{
private:
    int N,M;
public:
    dq_pow(){
        std::cin >> N>>M;
        
    }
    void start_pow(){
        int tmp=pow(N,M);
        if(tmp==0)
            std::cout << 10 << '\n';
        else
            std::cout << tmp<<'\n';
    }
    int pow(int a,int b){
        if(b==1)
            return a%10;
        if(b%2)
            return (pow(a,b-1)*a)%10;
        else{
            int tmp =pow(a,b/2)%10;
            return (tmp*tmp)%10;
        }
    }
};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        dq_pow dp;
        dp.start_pow();
    }

    return 0;
}