#include <iostream>
#include <vector>

#define INF 100000000
using namespace std;
class recursive_func{
private:
    vector<vector<vector<int>>> dp;
public:
    recursive_func(){
        dp.resize(21);
        for(int i=0;i<=20;i++)
            dp[i].resize(21);
        for(int i=0;i<=20;i++)
            for(int j=0;j<=20;j++)
                dp[i][j].resize(21,INF);
    };

    int DP(int a,int b,int c){
        if(a<=0||b<=0||c<=0)
            return 1;
        else if(a>20||b>20||c>20)
            return DP(20,20,20);
        if(dp[a][b][c]!=INF)
            return dp[a][b][c];
        
        if(a<b&&b<c)
            dp[a][b][c]=DP(a,b,c-1)+DP(a,b-1,c-1)-DP(a,b-1,c);
        else
            dp[a][b][c]=DP(a-1,b,c)+DP(a-1,b-1,c)+DP(a-1,b,c-1)-DP(a-1,b-1,c-1);
        return dp[a][b][c];
    }


};
int main(){
    recursive_func re;
    int a,b,c;
    while(1){
        std::cin >> a>> b>> c;
        if(a==-1&&b==-1&&c==-1)
            break;
        std::cout << "w("<<a<<", "<<b<<", "<<c<<") = ";
        std::cout << re.DP(a,b,c)<<'\n';
    }
    return 0;
}