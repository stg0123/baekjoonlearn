#include <iostream>
#include <vector>
using namespace std;
class interval_sum{
private:
    vector<int> dp;
    int N;
public:
    interval_sum(){
        std::cin >> N;
        dp.resize(N+1,0);
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=1;i<=N;i++){
            std::cin >>tmp;
            dp[i]=dp[i-1]+tmp;
        }
    }
    void find_sum(){
        int M,s,e;
        std::cin >> M;
        for(int i=0;i<M;i++){
            std::cin >> s >>e;
            std::cout << dp[e]-dp[s-1]<<'\n';
        }
    }

};
int main(){
    interval_sum is;
    is.find_sum();
    return 0;
}