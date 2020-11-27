#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int n,int m,vector<bool>& visit,int degree,vector<int>& num){
    if(degree == m){
        for(int i=0;i<m;i++)
            std::cout << num[i]<< ' '; 
        std::cout <<'\n';
        return ;
    }
    
    for(int i=1;i<=n;i++)
        if(!visit[i]){
            visit[i]=true;
            num[degree]=i;
            dfs(n,m,visit,degree+1,num);
            visit[i]=false;
        }
};


int main(){
    int n,m;
    std::cin >> n >> m;
    vector<bool> visit(n+1,false);
    vector<int> num(m,0);
    dfs(n,m,visit,0,num);
       
    return 0;
}