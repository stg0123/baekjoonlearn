#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class card_search{
private:
    vector<int> map;
    int N;
public :
    card_search(int n):N(n){
        map.resize(n);
    };
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> map[i];
        sort(map.begin(),map.end());
    }

    void start(){
        int n,val;
        std::cin >> n;
        for(int i=0;i<n;i++){
            std::cin >>val;
            search(val);
        }
    }
    void search(int a){
        
        vector<int>::iterator lb=lower_bound(map.begin(),map.end(),a);
        vector<int>::iterator ub=upper_bound(map.begin(),map.end(),a);
        if(*lb !=a){
            std::cout << 0<<'\n';
            return ;
        }

        std::cout << ub-lb<<'\n';

    }

};
int main(){
    int n;
    std::cin >> n;
    card_search cs(n);
    cs.set_val();
    cs.start();
    return 0;
}