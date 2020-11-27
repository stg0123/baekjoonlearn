#include <iostream>
#include <vector>

using namespace std;

void dfs(int start,int n,int m,int degree,vector<bool>& visit,vector<int>& num){
    if(visit[start]==true)
        return;
    num[degree]=start;
    if(degree==m-1){
        for(int i=0;i<m;i++)
            std::cout << num[i] << ' ';
        std::cout <<'\n';
        return ;
    }
    
    for(int i=1;i<=n;i++)
        dfs(i,n,m,degree+1,visit,num);
    
};
int main(){
    int n,m;
    std::cin >> n >> m;
    vector<bool> visit(n+1,false);
    vector<int> num(m,0);
    for(int i=1;i<=n;i++)
        dfs(i,n,m,0,visit,num);

    

    return 0;
}