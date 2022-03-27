#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class roof{
private:
    vector<pair<int,int>> val;
    int max_height=0,max_idx=0;
    int N;
public:
    roof(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<N;i++){
            std::cin >> a >> b;
            if(max_height<b){
                max_idx=a;
                max_height=b;
            }
            val.push_back({a,b});
        }
        sort(val.begin(),val.end());
    }
    void find_sol(){
        int sol=0;
        int last_idx=0,last_max=0;
        for(int i=0;i<val.size();i++){
            if(last_max<=val[i].second){
                sol+=(val[i].first-last_idx)*last_max;
                last_idx=val[i].first;
                last_max=val[i].second;
                if(last_idx==max_idx)
                    break;
            }
        }
        last_idx=val.size(),last_max=0;
        for(int i=val.size()-1;i>=0;i--){
            if(last_max<=val[i].second){
                sol+=(last_idx-val[i].first)*last_max;
                last_idx=val[i].first;
                last_max=val[i].second;
                if(last_idx==max_idx)
                    break;
            }
        }
        std::cout << sol+max_height << '\n';

    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    roof rf;
    rf.find_sol();

    return 0;
}