#include <iostream>
#include <vector>

using namespace std;
class sequence{
private:
    vector<long long> map;
public:
    sequence(){
        map.push_back(1);
        map.push_back(1);
        map.push_back(1);
    }
    
    long long cal(int n){
        long long sum=0;
        if(map.size()>n-1)
            return map[n-1];
        cal(n-1);
        sum= cal(n-3)+cal(n-2);
        map.push_back(sum);
        return sum;
    };
    
    void print_map(){
        for(int i=0;i<map.size();i++)
            std::cout << map[i]<<' ';
        std::cout << '\n';
        
    }

};
int main(){
    sequence S;
    int n,k;
    std::cin >>n;
    for(int i=0;i<n;i++){
        std::cin >> k;
        std::cout <<S.cal(k)<<'\n';
    }

    return 0;
}