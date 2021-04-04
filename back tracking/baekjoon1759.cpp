#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class password{
private:
    vector<char> alphabat;
    vector<bool> visit;
    vector<int> sol;
    int N,M;
public:
    password(){
        std::cin >> N >> M;
        sol.resize(N+1);
        visit.resize(M+1,false);
        set_val();
    }  
    void set_val(){
        char ch;
        for(int i=0;i<M;i++){
            std::cin >> ch;
            alphabat.push_back(ch);
        }
        sort(alphabat.begin(),alphabat.end());
    }
    void dfs(int n,int degree){
        sol[degree]=n;
        if(degree==N){
            int m=0,j=0;
            for(int i=1;i<=N;i++){
                if(alphabat[sol[i]-1]=='a'||alphabat[sol[i]-1]=='e'||alphabat[sol[i]-1]=='i'||alphabat[sol[i]-1]=='o'||alphabat[sol[i]-1]=='u')
                    m++;                
                else
                    j++;
            }
            if(m>0&&j>1){
                for(int i=1;i<=N;i++){
                    std::cout << alphabat[sol[i]-1];
                }
                std::cout << '\n';
            }
            return ;
        }
        for(int i=n+1;i<=M;i++){
            if(!visit[i]){
                visit[i]=true;
                dfs(i,degree+1);
                visit[i]=false;
            }
        }

    }

};
int main(){
    password ps;
    ps.dfs(0,0);
    return 0;
}
