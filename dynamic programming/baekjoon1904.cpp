#include <iostream>
#include <vector>

using namespace std;
class fibo{
private :
    vector<long long> map;
    int N;
public :
    fibo(int n):N(n){
        map.push_back(1);
        map.push_back(2);
    };

    long long cal(int n){
        long long sum=0;
        if(map.size()>n-1)
            return map[n-1];
        sum=(cal(n-2)+cal(n-1))%15746;
        map.push_back(sum);
        return sum;
    };
};
int main(){
    int n;
    std::cin >> n;
    fibo f(n);
    std::cout << f.cal(n)<<'\n';

    return 0;
}