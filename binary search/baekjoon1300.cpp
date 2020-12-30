#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,k;
    std::cin >> n >> k;
    int sol=1;
    int less_sum=0;
    int left=1,right=k,mid;
    while(left<=right){
        less_sum=0;
        mid=(left+right)/2;
        for(int i=1;i<=n;i++){
            if(i>=mid)
                break;
            else if(mid%i==0)
                less_sum+=min(mid/i-1,n);
            else 
                less_sum+=min(mid/i,n);
        }
        if(less_sum<=k-1){
            sol=mid;
            left=mid+1;
        }
        else
            right =mid-1;    
    }
    std::cout << sol<<'\n';
    return 0;
}