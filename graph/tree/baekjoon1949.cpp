#include <iostream>
#include <vector>
using namespace std;
struct _node{
    int parent;
    int persons;
    vector<int> child;
};
class prior_city{
private:
    vector<_node> city;
    vector<vector<int>> dp;
    int N,root;
public:
    prior_city(){
        std::cin >> N;
        city.resize(N+1);
        set_persons();
        set_connect();
        root=1;
        maketree(root,-1);
        dp.resize(N+1,vector<int>(2,-1));
    }
    void print_parent(){
        for(int i=1;i<=N;i++)
            std::cout << city[i].parent << ' ';
        std::cout << '\n';
    }
    void set_persons(){
        for(int i=1;i<=N;i++)
            std::cin >> city[i].persons;
    }
    void set_connect(){
        int a,b;
        for(int i=0;i<N-1;i++){
            std::cin >> a>>b;
            city[a].child.push_back(b);
            city[b].child.push_back(a);
        }
    }
    void maketree(int cur,int parent){
        city[cur].parent=parent;
        int erase_idx=-1;
        for(int i=0;i<city[cur].child.size();i++){
            if(city[cur].child[i]==parent){
                erase_idx=i;
                continue;
            }
            maketree(city[cur].child[i],cur);
        }
        if(erase_idx!=-1)
            city[cur].child.erase(city[cur].child.begin()+erase_idx);
    }
    void start_dp(){
        std::cout << max(DP(root,0),DP(root,1));
    }

    int DP(int idx,int n){
        if(dp[idx][n]!=-1)
            return dp[idx][n];
        int tmp;
        dp[idx][n]=0;
        if(n==0){
            for(int i=0;i<city[idx].child.size();i++){
                tmp=city[idx].child[i];
                dp[idx][n]+=max(DP(tmp,0),DP(tmp,1));
            }
        }
        else if(n==1){
            for(int i=0;i<city[idx].child.size();i++){
                tmp=city[idx].child[i];
                dp[idx][n]+=DP(tmp,0);
            }
            dp[idx][n]+=city[idx].persons;
        }
        return dp[idx][n];
    }
};
int main(){
    prior_city p_city;
    p_city.start_dp();

    return 0;
}