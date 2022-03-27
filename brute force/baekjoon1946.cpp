#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class junior{
private:
    vector<pair<int,int>> val;
    int N;
public:
    junior(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<N;i++){
            std::cin >> a >>b;
            val.push_back({a,b});
        }
        sort(val.begin(),val.end());
    }
    void print_val(){
        for(int i=0;i<val.size();i++){
            std::cout << val[i].first <<','<<val[i].second<<' ';
        }
    }
    void find_sol(){
        int tmp=N;
        int sol=N;
        for(int i=0;i<N;i++){
            if(tmp>=val[i].second)
                tmp = val[i].second;
            else
                sol--;
        }
        std::cout << sol <<'\n';
    }

};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        junior ju;
        ju.find_sol();
    }
    return 0;
}