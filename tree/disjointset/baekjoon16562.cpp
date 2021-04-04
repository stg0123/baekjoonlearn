#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int,int>& a,pair<int,int>& b){
    return a.second<b.second;
};
class friends{
private:
    vector<pair<int,int>> val;
    vector<int> parent;
    int N,M,K;
    int fnum=0;
public:
    friends(){
        std::cin >> N >> M >> K;
        parent.resize(N+1,-1);
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=1;i<=N;i++){
            std::cin >> a;
            val.push_back({i,a});
        }
        for(int i=0;i<M;i++){
            std::cin >>a >> b;
            merge(a,b);
        }
        sort(val.begin(),val.end(),compare);

    }
    int find(int n){
        if(parent[n]==-1)
            return n;
        return parent[n]=find(parent[n]);
    }
    bool merge(int a,int b){
        int p_a=find(a);
        int p_b=find(b);
        if(p_a==p_b)
            return false;
        parent[p_b]=p_a;
        fnum++;
        return true;
    }
    void find_sol(){
        int sol=0;
        for(int i=0;i<val.size();i++){
            if(merge(0,val[i].first)){
                if(K<val[i].second){
                    std::cout << "Oh no";  
                    return ;
                }
                K-=val[i].second;
                sol+=val[i].second;
                if(fnum==N){
                    std::cout << sol <<'\n';    
                    return ;
                }
            }
        }
    }


};
int main(){
    friends frd;
    frd.find_sol();
    return 0;
}