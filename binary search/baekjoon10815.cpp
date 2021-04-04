#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class b_search{
private:
    vector<int> val;
    int N;
public:
    b_search(){
        std::cin >> N;
        val.resize(N);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> val[i];
        sort(val.begin(),val.end());
    }
    void find(){
        int n,a;
        std::cin >> n;
        for(int i=0;i<n;i++){
            std::cin >> a;
            std::cout << binary_search(val.begin(),val.end(),a)<<' ';
        }
        

    }

};
int main(){
    b_search bs;
    bs.find();
    return 0;
}