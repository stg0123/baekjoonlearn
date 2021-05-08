#include <iostream>
#include <vector>
using namespace std;
class meanlight{
private:
    vector<vector<int>> sum;
    int N,M,K;
public:
    meanlight(){
        std::cin >> N >> M >> K;
        sum.resize(N+1,vector<int>(M+1,0));
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                std::cin >> tmp;
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+tmp; 
            }
        }
    }
    void find_sol(){
        int x1,y1,x2,y2;
        for(int i=0;i<K;i++){
            std::cin >> x1 >>y1 >>x2 >>y2;
            std::cout << (sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1])/((x2-x1+1)*(y2-y1+1))<<'\n';
        }
    }

};
int main(){
    meanlight ml;
    ml.find_sol();
    return 0;
}