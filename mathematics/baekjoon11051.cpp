#include <iostream>
#include <vector>

using namespace std;
class pascal{
private:
    vector<vector<int>> chache;
    int N;
public:
    pascal(int n):N(n){
        chache.resize(n+1);
        for(int i=0;i<=n;i++)
            chache[i].resize(i+1,1);
    };

    int dp(int n,int p){
        if(p==0||p==n)
            return 1;
        else if(chache[n][p]!=1)
            return chache[n][p];
        
        chache[n][p]=(dp(n-1,p-1)+dp(n-1,p))%10007;
        return chache[n][p];

    };
};
int main(){
    int n,p;
    std::cin >>n >> p;
    pascal pas(n);
    std::cout << pas.dp(n,p)<<'\n';
    return 0;
}