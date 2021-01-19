#include <iostream>
using namespace std;
class find_uni{
private:
    pair<int,int> p1,p2;
public:
    find_uni(){
        std::cin >> p1.first >> p1.second;
        std::cin >> p2.first >> p2.second;
    };

    bool cal_in(pair<int,int> point1,pair<int,int> point2,int rnd){
        int dx= point1.first-point2.first;
        int dy=point1.second-point2.second;
        if(dx*dx+dy*dy>rnd*rnd)
            return false;
        return true;
    };

    void find_num(){
        int x,y,rnd;
        int n,sol=0;
        std::cin >> n;
        for(int i=0;i<n;i++){
            std::cin >> x >> y >>rnd;
            if(cal_in(p1,{x,y},rnd)==!cal_in(p2,{x,y},rnd))
                sol++;
        }
        std::cout << sol << '\n';
    };
};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        find_uni fi;
        fi.find_num();
    }

    return 0;
}