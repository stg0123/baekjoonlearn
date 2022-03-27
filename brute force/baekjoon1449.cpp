#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class pipe{
private:
    vector<int> val;
    int N,L;
public:
    pipe(){
        std::cin >>  N >> L;
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >>tmp;
            val.push_back(tmp);
        }
        sort(val.begin(),val.end());
    }
    void find_sol(){
        int idx=0,sol=0;
        for(int i=0;i<val.size();i++){
            if(val[i]<=idx)
                continue;
            else{
                idx=val[i]+L-1;
                sol++;
            }
        }
        std::cout << sol;
    }

};
int main(){
    pipe pp;
    pp.find_sol();
    return 0;
}