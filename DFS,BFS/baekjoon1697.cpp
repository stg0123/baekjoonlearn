#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool check(vector<bool>& visit,int x){
    for(int i=0;i<visit.size();i++){
        if(visit[i]==x)
            return false;
    }
    return true;
};
void bfs(int n,int k){
    if(n==k){
        std::cout << 0;
        return;
    }
    queue<pair<int,int>> q;
    vector<bool> visit;
    visit.resize(200001,false);
    pair<int,int> tmp;
    int x,deg;
    tmp.first=n;
    tmp.second=0;
    q.push(tmp);
    visit[n]=true;
    while(!q.empty()){
        x=q.front().first;
        deg=q.front().second;
        //std::cout << "X="<< x << " deg=" << deg << '\n';
        if(x-1>=0&&!visit[x-1]){
            tmp.first=x-1;
            tmp.second=deg+1;
            q.push(tmp);
            visit[x-1]=true;
            if(x-1==k){
                std::cout << deg+1;
                return;
            }
        }
        if(x+1<=100000&&!visit[x+1]){
            tmp.first=x+1;
            tmp.second=deg+1;
            q.push(tmp);
            visit[x+1]=true;
            if(x+1==k){
                std::cout <<deg+1;
                return ;
            }
        }
        if(2*x<=100000&&!visit[2*x]){
            tmp.first=2*x;
            tmp.second=deg+1;
            q.push(tmp);
            visit[2*x]=true;
            if(2*x==k){
                std::cout <<deg+1;
                return ;
            }
        }
        q.pop();
    }
};

int main(){
    int n,k;
    std::cin >> n>>k;
    bfs(n,k);



    return 0;
}