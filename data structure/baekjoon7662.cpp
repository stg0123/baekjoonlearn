#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
class double_pq{
private:
    multiset<int> mset;
    int N;
public:
    double_pq(){
        std::cin >> N;
    }
    void oper(){
        char ch;
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >> ch >> tmp;
            if(ch=='I'){
                mset.insert(tmp);
            }
            else if(ch == 'D'){
                if(mset.empty())
                    continue;
                if(tmp==1){
                    mset.erase(--mset.end());
                }
                else if(tmp ==-1){
                    mset.erase(mset.begin());
                }
            }
        }
        if(mset.empty())
            std::cout << "EMPTY\n";
        else
            std::cout << *--mset.end() << ' '<<*mset.begin()<<'\n';

    }

};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        double_pq dp;
        dp.oper();
    }

    return 0;
}