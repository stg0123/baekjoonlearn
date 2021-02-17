#include <iostream>
#include <vector>
using namespace std;
class interaction{
private:
    vector<vector<int>> sum;
    string str;
public:
    interaction(){
        std::cin >> str;
        sum.resize(str.size()+1,vector<int>(26,0));
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=0;i<str.size();i++){
            tmp =str[i]-'a';
            for(int j=0;j<26;j++){
                sum[i+1][j]=sum[i][j];
                if(j==tmp)
                    sum[i+1][j]++;
            }
        }
    }
    void find_sol(){
        int M,s,e,tmp;
        char ch;
        std::cin >> M;
        for(int i=0;i<M;i++){
            std::cin >> ch >> s >> e;
            tmp =ch-'a';
            std::cout << sum[e+1][tmp]-sum[s][tmp]<<'\n';
        }
    }

};
int main(){
    interaction it;
    it.find_sol();
    return 0;
}