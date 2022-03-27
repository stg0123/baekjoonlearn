#include <iostream>
#include <vector>
using namespace std;
int dx[6]={-1,0,0,-1,1,1};
int dy[6]={-1,-1,1,1,-1,1};
class cutning{
private:
    vector<vector<int>> link;
    vector<bool> visit;
    vector<int> sol;
    int N,M;
    int even=0,odd=0;
public:
    cutning(){
        std::cin >> N >> M;
        set_val();
        visit.resize(odd+1);
        sol.resize(odd+1);
    }
    void set_val(){
        char ch;
        vector<vector<int>> map(N,vector<int>(M,0));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                std::cin >>ch;
                if(ch=='.')
                    map[i][j]=1;
            }
        }
        for(int j=0;j<M;j++){
            for(int i=0;i<N;i++){
                if(map[i][j]){
                    if(j%2==0)
                        map[i][j]=++even;
                    else
                        map[i][j]=++odd;
                }
            }
        }
        link.resize(even+1);
        
        for(int j=0;j<M;j+=2){
            for(int i=0;i<N;i++){
                if(map[i][j]){
                    for(int l=0;l<6;l++){
                        if(i+dx[l]>=0&&i+dx[l]<N&&j+dy[l]>=0&&j+dy[l]<M)
                            if(map[i+dx[l]][j+dy[l]])
                                link[map[i][j]].push_back(map[i+dx[l]][j+dy[l]]);
                    }
                }
            }
        }
    }
    int dfs(int n){
        for(int i : link[n]){
            if(visit[i])
                continue;
            visit[i]=true;
            if(sol[i]==0 || dfs(sol[i])){
                sol[i]=n;
                return 1;
            }
        }
        return 0;
    }
    void bi_matching(){
        int result =0;
        for(int i=1;i<=even;i++){
            fill(visit.begin(),visit.end(),false);
            result+=dfs(i);
        }
        std::cout << even+odd-result <<'\n';
    }

};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        cutning cu;
        cu.bi_matching();
    }
    
    return 0;
}