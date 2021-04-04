#include <iostream>
#include <vector>
using namespace std;
class advior{
private:
    int N;
    vector<pair<int,int>> map;
public:
    advior(){
        std::cin >> N;
        map.resize(N+1);
        set_val();
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> map[i].first >> map[i].second;
    }
    int find(int now){
        if(now>N)
            return 0;
        if(now+map[now].first-1>N)
            return 0;
        else{
            int tmp=N;
            int tmp2=0;
            for(int i=now+map[now].first;i<=tmp;i++){
                tmp2=max(tmp2,find(i));
                tmp=min(tmp,map[i].first+i-1);
            }
            return map[now].second+tmp2;
        }
    }
    void find_sol(){
        int tmp=N;
        int sol=0;
        for(int i=1;i<=tmp;i++){
            sol=max(sol,find(i));
            tmp=min(tmp,map[i].first+i-1);
        }
        std::cout << sol;
    }


};
int main(){
    advior ad;
    ad.find_sol();
    return 0;
}