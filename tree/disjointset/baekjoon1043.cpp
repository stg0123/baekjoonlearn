#include <iostream>
#include <vector>
using namespace std;
class lie{
private:
    vector<int> parent;
    int N,M;
public:
    lie(){ 
        std::cin >> N >> M;
        parent.resize(N+1,-1);
        set_val();
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
        return true;
    }
    void set_val(){
        int n,a;
        std::cin >> n;
        for(int i=0;i<n;i++){
            std::cin >> a;
            merge(0,a);
        }
    }
    void find_sol(){
        int n,sol=0,b;
        vector<int> party(M,0);
        for(int i=0;i<M;i++){
            std::cin >> n;
            if(n==0)
                continue ;
            std::cin >> party[i];
            for(int j=1;j<n;j++){
                std::cin >> b;
                merge(party[i],b);
            }
        }
        for(int i=0;i<M;i++){
            if(find(party[i])!=find(0))
                sol++;
        }
        std::cout << sol;
        

    }
};
int main(){
    lie l;
    l.find_sol();
    return 0;
}