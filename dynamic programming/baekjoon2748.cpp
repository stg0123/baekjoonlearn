#include <iostream>
#include <vector>
using namespace std;

class map{
private:
    vector<long long> maps;
    int N;
public:
    map(int n):N(n){
        maps.push_back(0);
        maps.push_back(1);
    };
    long long fibonachi(int n)
    {
        if(maps.size()>n)
            return maps[n];
        else{
            long long tmp=fibonachi(n - 1) + fibonachi(n - 2);
            maps.push_back(tmp);
            //print_map();
            return tmp;
        }
    };
    void print_map(){
        for(int i=0;i<maps.size();i++)
            std::cout << maps[i] << ' ';
        std::cout <<'\n';
    };
};
int main(){
    int n;
    std::cin >> n;
    map m(n);
    std::cout << m.fibonachi(n);
    return 0;
}