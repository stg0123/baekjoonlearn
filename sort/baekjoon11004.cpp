#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int N,K,a;
    std::cin >> N >> K;
    vector<int> val;
    for(int i=0;i<N;i++){
        std::cin >> a;
        val.push_back(a);
    }
    sort(val.begin(),val.end());
    std::cout << val[K-1];

    return 0;
}