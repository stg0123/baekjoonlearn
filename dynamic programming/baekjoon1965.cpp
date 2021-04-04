#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class LIS{
private:
    vector<int> val;
    int N;
public:
    LIS(){
        std::cin >> N;
    }
    void find_LIS(){
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            if(i==0 || val.back()<tmp)
                val.push_back(tmp);
            else
                *lower_bound(val.begin(),val.end(),tmp) =tmp;
        }
        std::cout << val.size();
    }
};
int main(){
    LIS lis;
    lis.find_LIS();
    return 0;
}