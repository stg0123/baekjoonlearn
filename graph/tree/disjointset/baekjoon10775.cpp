#include <iostream>
#include <vector>
using namespace std;
class docking{
private:
    vector<int> parent;
    int G,K;
public:
    docking(){
        std::cin >> G >> K;
        parent.resize(G+1,-1);
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
    void find_docking(){
        int idx,p_idx;
        int sol=0;
        for(int i=0;i<K;i++){
            std::cin >> idx;
            p_idx=find(idx);
            if(p_idx==0)
                break;
            merge(p_idx-1,p_idx);
            sol++;
        }
        std::cout << sol;

    }


};
int main(){
    docking dk;
    dk.find_docking();
    return 0;
}