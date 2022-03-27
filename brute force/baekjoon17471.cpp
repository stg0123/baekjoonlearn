#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int INF=1000000000;
struct node{
    int people;
    vector<int> edge;  
};
class baekjoon{
private:
    vector<node> region;
    vector<bool> visit;
    int N,SUM=0;
public:
    baekjoon(){
        std::cin >> N;
        region.resize(N+1);
        visit.resize(N+1);
        set_val();
    }
    void set_val(){
        for(int i=1;i<=N;i++){
            std::cin >> region[i].people;
            SUM+=region[i].people;
        }
        int a,b;
        for(int i=1;i<=N;i++){
            std::cin >> a;
            for(int j=0;j<a;j++){
                std::cin >> b;
                region[i].edge.push_back(b);
                region[b].edge.push_back(i);
            }
        }
        
    }
    bool check(vector<bool>& split){
        vector<int> visit(N+1,false);
        queue<int> q;
        int sol=0;
        for(int i=0;i<split.size();i++){
            if(split[i]){
                visit[i+1]=true;
                q.push(i+1);
                break;
            }
        }
        for(int i=0;i<split.size();i++){
            if(!split[i]){
                visit[i+1]=true;
                q.push(i+1);
                break;
            }
        }
        int cur;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            sol++;
            for(int i : region[cur].edge){
                if(!visit[i] && split[cur-1] == split[i-1]){
                    visit[i]=true;
                    q.push(i);
                }
            }
        }
        if(sol==N)
            return true;
        return false;
    }
    void find_sol(){
        int sol=INF;
        for(int i=1;i<=N/2;i++){
            vector<bool> split(N,false);
            for(int j=0;j<i;j++)
                split[j]=true;
            do{
                if(check(split)){
                    int a=0;
                    for(int i=0;i<N;i++){
                        if(split[i])
                            a+=region[i+1].people;
                    }
                    sol=min(sol,abs(SUM-2*a));
                }
            }while(prev_permutation(split.begin(),split.end()));
        }
        if(sol==INF)
            std::cout << -1 << '\n';
        else
            std::cout << sol << '\n';
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    baekjoon bj;
    bj.find_sol();
    return 0;
}