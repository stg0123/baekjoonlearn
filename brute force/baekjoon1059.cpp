#include <iostream>
#include <vector>
using namespace std;
class goodinterval{
private:
    vector<int> val;
    int L,N;
public:
    goodinterval(){
        std::cin >> L;
        val.resize(L);
        set_val();
        std::cin >> N;
    }
    void set_val(){
        for(int i=0;i<L;i++)
            std::cin >> val[i];
    }
    void find_sol(){
        int MIN_MAX=0,MAX_MIN=1001;
        for(int i=0;i<L;i++){
            if(val[i]<=N )
                MIN_MAX = max(MIN_MAX,val[i]);
            if(N<=val[i])
                MAX_MIN = min(MAX_MIN,val[i]);
        }
        if(MIN_MAX == N || MAX_MIN ==N)
            std::cout << 0 << '\n';
        else
            std::cout << (N-MIN_MAX)*(MAX_MIN-N)-1 << '\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    goodinterval gi;
    gi.find_sol();

    return 0;
}