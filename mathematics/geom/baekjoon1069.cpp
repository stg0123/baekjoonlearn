#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class distance_find{
private:
    double sol;
    double left_dis;
    int D,T;
public:
    distance_find(){
        int x,y;
        std::cin >> x >> y;
        left_dis = hypot(x,y);
        std::cin >> D >> T;
        sol=0;
    }
    void cal(){
        if(D<=T){
            printf("%.10lf",left_dis);
            return ;
        }
        while(left_dis>0){
            if(left_dis>2*D){
                left_dis-=D;
                sol+=T;
            }
            else if(left_dis>D){
                double tmp1=left_dis-D;
                sol+=min(T+tmp1,(double)(2*T));
                left_dis=0;
                break;
            }
            else{
                double tmp = min((D-left_dis)+T,left_dis);
                tmp=min(tmp,(double)(2*T));
                sol+=tmp;
                left_dis=0;
                break;
            }
        }
        printf("%.10lf",sol);
    }

};
int main(){
    distance_find df;
    df.cal();
    return 0;
}