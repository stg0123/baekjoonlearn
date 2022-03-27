#include <iostream>
#include <vector>
using namespace std;
class union_find{
private:
    vector<int> parent;
    int N;
public:
    union_find(){
        std::cin >> N;
        parent.resize(N+1,-1);
    }
    int find(int n){
        if(parent[n]<0)
            return n;
        return parent[n]=find(parent[n]);
    }

    void merge(int a,int b){
        int p_a=find(a);
        int p_b=find(b);
        if(p_a==p_b)
            return ;
        parent[p_a]=p_b;
    }


};
int main(){
    
    union_find un;
    int m;
    std::cin >> m;
    int type,a,b;
    for(int i=0;i<m;i++){
        std::cin >> type >> a >> b;
        if(type==0)
            un.merge(a,b);
        else if(type ==1){
            if(un.find(a)==un.find(b))
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
    }
    return 0;
}