#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,max=1;
    std::cin >> n;
    vector<int> map(n);
    vector<int> dp(n,1);
    for(int i=0;i<n;i++)
        std::cin >>map[i];
    
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            if(map[i]>map[j]&&dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                if(max<dp[i])
                    max=dp[i];
            }
    std::cout << max<<'\n';

    return 0;
}