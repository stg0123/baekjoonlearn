#include <iostream>
#include <vector>
using namespace std;
class travel{
private:
    vector<int> parent;
    int N,M;
public:
    travel(){
        std::cin >> N>> M;
        parent.resize(N+1,-1);
        set_val();
    }
    void set_val(){
        int a;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                std::cin >> a;
                if(a)
                    merge(i,j);
            }
        }
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
    void connect(){
        bool flag=true;
        int a,p;
        std::cin >> a;
        p=find(a);
        for(int i=1;i<M;i++){
            std::cin >> a;
            if(p!=find(a))
                flag=false;
        }
        if(flag)
            std::cout << "YES";
        else
            std::cout << "NO";
    }

};
int main(){ 
    travel tr;
    tr.connect();

    return 0;
}