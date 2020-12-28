#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int a,int b){
    return a>b;
};
class namu{
private:
    vector<int> map;
    int N,M;
    int max;
public:
    namu(int n,int m):N(n),M(m){
        map.resize(n);
        max=0;
    };
    void set_val(){
        for(int i=0;i<N;i++){
            std::cin >> map[i];
            if(map[i]>max)
                max=map[i];
        }
        sort(map.begin(),map.end(),compare);
    };
    long long cal(int n){
        long long sum=0;
        for(int i=0;i<N;i++){
            if(map[i]>n)
                sum+=map[i]-n;
            else
                break;
        }
        return sum;
    }

    void bi_search(){
        long long left=0,right=max;
        long long mid,sol;
        long long sum;
        while(left<=right){
            mid=(left+right)/2;
            if((long long)M<=cal(mid)){
                sol=mid;
                left=mid+1;
            }
            else
                right=mid-1;
        }
        std::cout << sol<<'\n';

    };

};
int main(){
    int n,m;
    std::cin >> n >> m;
    namu na(n,m);
    na.set_val();
    na.bi_search();

    return 0;
}