#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class lining{
private:
    vector<int> lis;
    int N;
public:
    lining(){
        std::cin >> N;
    }
    void find_sol(){
        int a;
        for(int i=0;i<N;i++){
            std::cin >>a;
            if(lis.empty())
                lis.push_back(a);
            else if(lis.back()<a)
                lis.push_back(a);
            else 
                *lower_bound(lis.begin(),lis.end(),a) = a;
        }
        std::cout << N-lis.size()<<'\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    lining li;
    li.find_sol();

    return 0;
}