#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
bool compare_max(int& a,int& b){
    return a>b;
};
class tiling{
private:
    vector<int> one,two;
    int N,A,B;
public:
    tiling(){
        std::cin >> N >> A >> B;
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=0;i<A;i++){
            std::cin >> tmp;
            one.push_back(tmp);
        }
        for(int i=0;i<B;i++){
            std::cin >> tmp;
            two.push_back(tmp);
        }
        sort(one.begin(),one.end(),compare_max);
        sort(two.begin(),two.end(),compare_max);
    }
    void find_val(){
        vector<int> sol;
        int one_idx=0;
        int two_idx=0;
        int sol_idx=0;
        while(N>1&&two_idx<B){
            sol.push_back(two[two_idx++]);
            N-=2;
            sol_idx++;
        }
        sol_idx--;
        for(int i=0;i<N;i++){
            sol.push_back(one[one_idx++]);
        }
        int tmp;
        while(A-one_idx>=2&&sol_idx>=0){
            tmp=one[one_idx]+one[one_idx+1];
            one_idx+=2;
            std::cout << tmp <<' '<<one_idx<< '\n';
            if(tmp>sol[sol_idx]){
                sol[sol_idx]=tmp;
                sol_idx--;
            }
            else
                break;
        }
        int result=0;
        for(int i=0;i<sol.size();i++){
            result+=sol[i];
        }
        std::cout << result;
    }
};
int main(){
    tiling ti;
    ti.find_val();
    return 0;
}