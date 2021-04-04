#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class max_diff{
private:
    vector<int> val;
    int N;
public:
    max_diff(){
        std::cin >> N;
        val.resize(N);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> val[i];
        sort(val.begin(),val.end());
    }
    void find_sol(){
        int sol=0;
        int tmp;
        do{
            tmp=0;
            for(int i=0;i<N-1;i++)
                tmp+=abs(val[i]-val[i+1]);
            sol=max(sol,tmp);
        }while(next_permutation(val.begin(),val.end()));
        std::cout << sol;
    }
};
int main(){
    max_diff md;
    md.find_sol();
    return 0;
}