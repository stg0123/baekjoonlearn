#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
double INF = (double)4000000;
class vectorsum{
private:
    vector<pair<ll,ll>> point;
    pair<ll,ll> sum;
    int N;
public:
    vectorsum(){
        std::cin >> N;
        point.resize(N);
        sum={0,0};
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++){
            std::cin >> point[i].first >> point[i].second;
            sum.first+=point[i].first;
            sum.second+=point[i].second;
        }
    }
    void find_sol(){
        double MIN_distance= INF;
        vector<bool> check(N,false);
        for(int i=0;i<N/2;i++)
            check[i]=true;
        do{
            pair<ll,ll> tmp =sum;
            for(int i=0;i<N;i++){
                if(check[i]){
                    tmp.first-=point[i].first*2;
                    tmp.second-=point[i].second*2;
                }
            }
            MIN_distance = min(MIN_distance,distance(tmp));
        }while(prev_permutation(check.begin(),check.end()));
        std::cout << fixed;
        std::cout.precision(10);
        std::cout << MIN_distance << '\n';

    }
    double distance(pair<ll,ll>& p1){
        ll x = p1.first*p1.first;
        ll y = p1.second*p1.second;
        return sqrt(x+y);      
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        vectorsum vs;
        vs.find_sol();
    }
    return 0;
}