#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    std::cin >> n;
    vector<pair<int,int>> map;
    vector<int> dp;
    dp.resize(n,1);
    int tmp1,tmp2;
    for(int i=0;i<n;i++){
        std::cin >> tmp1 >> tmp2;
        map.push_back(make_pair(tmp1,tmp2));
    }
    sort(map.begin(),map.end());
    int max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++)
            if(map[i].second>map[j].second&&dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                if(max<dp[i])
                    max=dp[i];
            }
    }
    std::cout << n-max<<'\n';

    return 0;
}