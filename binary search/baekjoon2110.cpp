#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class setting{
private:
    vector<int> map;
    int N,M,max;
public:
    setting(int n,int m):N(n),M(m){
        map.resize(n);
        max=0;
    };
    void set_val(){
        for(int i=0;i<N;i++){
            std::cin >>map[i];
            if(max<map[i])
                max=map[i];
        }
        sort(map.begin(),map.end());
    };
    int cal(int gap){
        int sum=1;
        int tmp=map[0];
        for(int i=1;i<N;i++){
            if(map[i]-tmp>=gap){
                sum++;
                tmp=map[i];
            }
        }
        return sum;

    };
    
    void bi_search(){
        int left=1,right=max;
        int mid,sol;
        int sum=0;
        while(left<=right){
            mid=(left+right)/2;
            sum=cal(mid);
            std::cout << "sum:"<<sum <<",mid:"<<mid<<'\n';
            if(M<=sum){
                sol=mid;
                left=mid+1;
            }
            else
                right=mid-1;
        }
        std::cout <<sol<<'\n';
        
    }

};
int main(){
    int n,m;
    std::cin >> n >> m;
    setting se(n,m);
    se.set_val();
    se.bi_search();

    return 0;
}