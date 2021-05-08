#include <iostream>
#include <vector>
using namespace std;
class breed{
private:
    vector<vector<int>> sum;
    int N,M;
public:
    breed(){
        std::cin >> N >> M;
        sum.resize(N+1,vector<int>(3,0));
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=1;i<=N;i++){
            std::cin >> tmp;
            for(int j=0;j<3;j++){
                sum[i][j]=sum[i-1][j];
                if(j==tmp-1)
                    sum[i][j]++;
            }
            
        }
    }
    void find_interval(){
        int s,e;
        for(int i=0;i<M;i++){
            std::cin >> s >> e;
            for(int j=0;j<3;j++){
                std::cout << sum[e][j]-sum[s-1][j]<<' ';
            }
            std::cout <<'\n';
        }
    }


};
int main(){
    breed br;
    br.find_interval();

    return 0;
}