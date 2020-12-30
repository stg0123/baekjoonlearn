#include <iostream>
#include <vector>
using namespace std;
class metix_mul{
private:
    vector<vector<int>> m1,m2;
public :
    metix_mul(){
    };
    void set_val(){
        int n,m,tmp;
        std::cin >> n>>m;
        m1.resize(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                std::cin >>tmp;
                m1[i].push_back(tmp);
            }
        
        std::cin >> n>>m;
        m2.resize(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                std::cin >>tmp;
                m2[i].push_back(tmp);
            }
        

    }
    void start(){
        for(int i=0;i<m1.size();i++)
            mul(i);

    }
    void mul(int n){
        int sum=0;
        for(int j=0;j<m2[0].size();j++){
            sum=0;
            for(int i=0;i<m2.size();i++){
                sum+=m1[n][i]*m2[i][j];
            }
            std::cout <<sum << ' ';
        }
        std::cout <<'\n';
    }
};
int main(){
    metix_mul m;
    m.set_val();
    m.start();
    return 0;
}