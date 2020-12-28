#include <iostream>
#include <vector>
#include <set>
using namespace std;
class cutting{
private:
    vector<long long> map;
    int N,M,max;
public:
    cutting(int n, int m):N(n),M(m){
        map.resize(n);
        max=0;
    };
    void set_val(){
        for(int i=0;i<N;i++){
            std::cin >>map[i];
            if(max<map[i])
                max=map[i];
        }
    }
    long long cal(int mid){
        long long sum=0;
        for(int i=0;i<N;i++)
            sum+=map[i]/mid;

        return sum;
    }
    void find_val(){
        long long left=1,right=max;
        long long mid;
        long long sum,sol;
        while(left<=right){
            mid=(left+right)/2;
            sum=cal(mid);

            if(M<=sum){
                sol=mid;
                left=mid+1;
            }
            else
                right=mid-1;
        }
        std::cout << sol<<'\n';
    }

    
};


int main(){
    int n,m;
    std::cin >> n >> m;
    cutting cu(n,m);
    cu.set_val();
    cu.find_val();
    return 0;
}