#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class bi_search{
private:
    vector<int> map;
    int N;
public:
    bi_search(int n):N(n){
        map.resize(n);
    };

    void set_val(){
        int a;
        for(int i=0;i<N;i++){
            std::cin>> map[i];
        }
        sort(map.begin(),map.end());
    }
    void start(){
        int n,val;
        std::cin >> n;
        for(int i=0;i<n;i++){
            std::cin >> val;
            search(val);
        }
    }
    void search(int a){
        int left=0,right=N-1;
        int mid;
        if(a<map[0]||map[right]<a){
            std::cout << 0<<'\n';
            return ;
        }
        while(left<=right){
            mid=(left+right)/2;
            if(map[mid]==a){
                std::cout << 1<<'\n';
                return ;
            }
            else if(map[mid]<a)
                left=mid+1;
            else if(map[mid]>a)
                right=mid-1;
        }
        std::cout << 0<<'\n';
    };
};
int main(){
    int n;
    std::cin >> n;
    bi_search bi(n);
    bi.set_val();
    bi.start();
    return 0;
}
