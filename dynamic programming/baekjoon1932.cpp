#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
class tri{
private:
    vector<vector<int>> cal;
    vector<vector<int>> map;
    int N;
public:
    tri(int n):N(n){
        map.resize(n+1);
        for(int i=1;i<=n;i++)
            map[i].resize(i+1,0);
        
        cal.resize(n+1);
        for(int i=1;i<=n;i++)
            cal[i].resize(i+1,-1);
    };

    void set_num(){
        for(int i=1;i<=N;i++)
            for(int j=1;j<=i;j++)
                std::cin >> map[i][j];
        cal[1][1]=map[1][1];
    };

    void print_map(){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=i;j++)
                std::cout << map[i][j]<<' ';
        std::cout <<'\n';
        }
    };
    void print_cal(){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=i;j++)
                std::cout << cal[i][j]<<' ';
        std::cout <<'\n';
        }
    };
    int DP(int n,int k){
        int tmp;

        if(cal[n][k]!=-1)
            return cal[n][k];
        if(n==k)
            tmp=DP(n-1,k-1)+map[n][k];
        else if(k==1)
            tmp=DP(n-1,k)+map[n][k];
        else 
            tmp=max(DP(n-1,k-1),DP(n-1,k))+map[n][k];
        
        cal[n][k]=tmp;

        return tmp;

    };
};
int main(){
    int n,max,sum;
    max=0;
    std::cin >>n;
    tri t(n);
    t.set_num();
    for(int i=1;i<=n;i++){
        sum=t.DP(n,i);
        if(sum>max)
            max=sum;
    }
    std::cout << max;
    return 0;
}