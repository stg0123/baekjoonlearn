#include <iostream>
#include <vector>
using namespace std;
class sq{
private:
    vector<int> presum;
    int N,K;
public:
    sq(){
        std::cin >> N >> K;
        presum.resize(N+1,0);
        set_val();
    }
    void set_val(){
        int a;
        for(int i=1;i<=N;i++){
            std::cin >> a;
            presum[i]=a+presum[i-1];
        }
    }
    void find_sol(){
        int sol=-100*N;
        for(int i=K;i<=N;i++){
            sol=max(sol,presum[i]-presum[i-K]);
        }
        std::cout << sol << '\n';
    }

};
int main(){
    sq ss;
    ss.find_sol();
    return 0;
};
