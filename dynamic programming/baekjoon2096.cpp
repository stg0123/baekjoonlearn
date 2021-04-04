#include <iostream>
#include <vector>
using namespace std;
class stair{
private:
    vector<int> max_dp1,max_dp2,min_dp1,min_dp2;
    int N;
public:
    stair(){
        std::cin >> N;
        max_dp1.resize(3);
        max_dp2.resize(3);
        min_dp1.resize(3);
        min_dp2.resize(3);
    }
    void DP(){
        int tmp;
        for(int i=0;i<3;i++)
            std::cin >> max_dp1[i];
        min_dp1=max_dp1;
        for(int i=1;i<N;i++){
            for(int j=0;j<3;j++){
                if(j==0){
                    max_dp2[j]=max(max_dp1[0],max_dp1[1]);
                    min_dp2[j]=min(min_dp1[0],min_dp1[1]);
                }
                else{
                    max_dp2[j]=max(max_dp1[1],max_dp1[2]);
                    min_dp2[j]=min(min_dp1[1],min_dp1[2]);
                }
                if(j==1){
                    max_dp2[j]=max(max_dp2[j],max_dp1[0]);
                    min_dp2[j]=min(min_dp2[j],min_dp1[0]);
                }
                std::cin >> tmp;
                max_dp2[j]+=tmp;
                min_dp2[j]+=tmp;
            }
            max_dp1=max_dp2;
            min_dp1=min_dp2;
        }
        int sol=max(max_dp1[0],max_dp1[1]);
        std::cout << max(sol,max_dp1[2])<<' ';
        sol=min(min_dp1[0],min_dp1[1]);
        std::cout << min(sol,min_dp1[2]);
    }

};
int main(){
    stair st;
    st.DP();
    return 0;
}