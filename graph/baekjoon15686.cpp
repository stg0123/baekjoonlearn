#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int INF =2000000000;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
struct _node{
    int x,y,degree;
};
class chicken{
private:
    vector<pair<int,int>> home,ck;
    int N,M;
public:
    chicken(){
        std::cin >> N >> M;
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                std::cin >> tmp;
                if(tmp==1)
                    home.push_back({i,j});
                else if(tmp==2)
                    ck.push_back({i,j});
            }
        }
    }
    int find_dis(vector<int>& combination){
        int dis=0,tmp;
        for(int i=0;i<home.size();i++){
            tmp=INF;
            for(int j=0;j<ck.size();j++){
                if(combination[j])
                    tmp=min(tmp,abs(home[i].first-ck[j].first)+abs(home[i].second-ck[j].second));
            }
            dis+=tmp;
        }
        
        return dis;
    }

    void find_sol(){
        int sol= INF;
        vector<int> combination(ck.size(),0);
        for(int i=1;i<=M;i++)
            combination[ck.size()-i]=1;
        do{
            sol = min(sol,find_dis(combination));
        
        }while(next_permutation(combination.begin(),combination.end()));
        std::cout << sol << '\n';
    }

};
int main(){
    cout.tie(NULL);cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    chicken ck;
    ck.find_sol();

    return 0;
}