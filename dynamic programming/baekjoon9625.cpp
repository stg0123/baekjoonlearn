#include <iostream>
#include <vector>
using namespace std;
class babba{
private:
    vector<pair<int,int>> AB;
    int K;
public:
    babba() {
        std::cin >>K;
        AB.resize(K+1,{-1,-1});
        AB[0]={1,0};
    }
    pair<int,int> DP(int k){
        if(AB[k].first!=-1)
            return AB[k];
        pair<int,int> tmp = DP(k-1);
        AB[k].first=tmp.second;
        AB[k].second=tmp.first+tmp.second;
        return AB[k];
    };
    void find_sol(){
        pair<int,int> tmp = DP(K);
        std::cout << tmp.first << ' ' << tmp.second << '\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    babba ba;
    ba.find_sol();

    return 0;
}