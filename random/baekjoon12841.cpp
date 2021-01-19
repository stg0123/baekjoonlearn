#include <iostream>
#include <vector>
using namespace std;
#define INF 20000000000
class minju{
private:
    vector<int> cross,left,right;
    long long right_sum;
    int N;
public:
    minju(){
        std::cin >> N;
        right_sum=0;
        set_val();
    }
    void set_val(){
        int a;
        for(int i=0;i<N;i++){
            std::cin >> a;
            cross.push_back(a);
        }
        for(int i=0;i<N-1;i++){
            std::cin >> a;
            left.push_back(a);
        }
        for(int i=0;i<N-1;i++){
            std::cin >> a;
            right.push_back(a);
            right_sum+=a;
        }
    }

    void find_min_dis(){
        long long left_sum=0;
        long long sol_idx,sol_sum=INF,tmp;
        for(int i=0;i<N;i++){
            tmp=left_sum+cross[i]+right_sum;
            if(tmp<sol_sum){
                sol_sum=tmp;
                sol_idx=i;
            }
            if(i==N-1)
                break;
            left_sum+=left[i];
            right_sum-=right[i];
        }
        std::cout << sol_idx+1<<' '<<sol_sum;

    }

};
int main(){
    minju mi;
    mi.find_min_dis();

    return 0;
}