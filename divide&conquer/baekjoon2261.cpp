#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
struct p{
    int first,second;
    bool operator<(const p& b)const{
        return second == b.second ? first < b.first : second < b.second ; 
    }
};
bool compare(p& a,p& b){
    return a.first == b.first ? a.second<b.second : a.first <b.first;
};
class min_dis{
private:
    vector<p> map;
    set<p> setting;
    int N;
public:
    min_dis(int n):N(n){
        
    };
    void set_val(){
        int tmp1,tmp2;
        for(int i=0;i<N;i++){
            std::cin >> tmp1>>tmp2;
            map.push_back({tmp1,tmp2});
        }
        sort(map.begin(),map.end(),compare);
    };


    int dis(p loc1,p loc2){
        int dx=loc1.first-loc2.first;
        int dy=loc1.second-loc2.second;
        return (dx*dx)+(dy*dy);

    }

    void find_min(){
        int pos=0,dx,tmp;
        int MIN=dis(map[0],map[1]);
        setting={map[0],map[1]};
        for(int i=2;i<N;i++){
            while(pos<i){
                dx=map[i].first-map[pos].first;
                if(dx*dx>MIN){
                    setting.erase(map[pos++]);
                }
                else 
                    break;
            }
            auto low =setting.lower_bound({-10001,map[i].second - sqrt(MIN)-1});
            auto upp =setting.upper_bound({-10001,map[i].second + sqrt(MIN)+1});

            for(auto j=low;j!=upp;j++){
                MIN= min(MIN,dis(map[i],*j));
            }
            setting.insert(map[i]);
        }
        std::cout << MIN<<'\n';
    }
};
int main(){
    int n;
    std::cin >> n;
    min_dis md(n);
    md.set_val();
    md.find_min();

    return 0;
}