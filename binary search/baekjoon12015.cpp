#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    std::cin >> n;
    vector<int> dp;
    int temp,sum;
    std::cin >> temp;
    dp.push_back(temp);
    for(int i=1;i<n;i++){
        std::cin >> temp;
        if(temp>dp.back())
            dp.push_back(temp);
        else if(temp<dp.back())
            *lower_bound(dp.begin(),dp.end(),temp)=temp;
    }
    std::cout<<dp.size()<<'\n';
    return 0;
}