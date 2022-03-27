#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector<int> num;
    num.resize(3);
    for(int i=0;i<3;i++)
        std::cin  >> num[i];
    sort(num.begin(),num.end());
    for(int i : num)
        std::cout << i <<' ';

    return 0;
}