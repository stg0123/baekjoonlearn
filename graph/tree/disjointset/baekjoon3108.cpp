#include <iostream>
#include <vector>
using namespace std;
class turtle{
private:
    vector<int> parent;
    vector<vector<int>> map;
    int N;
    int sol;
public:
    turtle(){
        std::cin >> N;        
        parent.resize(N+2,-1);
        map.resize(1001,vector<int>(1001,0));
        sol=N;
    }
    int find(int n){
        return parent[n]==-1 ? n : parent[n]=find(parent[n]);
    }
    bool merge(int a,int b){
        int p_a=find(a);
        int p_b=find(b);
        if(p_a==p_b)
            return false;
        parent[p_b]=p_a;
        sol--;
        return true;
    }
    void find_sol(){
        int x1,y1,x2,y2;
        map[500][500]=N+1;
        for(int i=1;i<=N;i++){
            std::cin >> x1 >>y1 >>x2 >>y2;
            x1+=500,y1+=500,x2+=500,y2+=500;
            for(int j=x1;j<=x2;j++){
                if(map[j][y1])
                    merge(map[j][y1],i);
                else
                    map[j][y1]=i;
                if(map[j][y2])
                    merge(map[j][y2],i);
                else
                    map[j][y2]=i;    
            }
            for(int j=y1;j<=y2;j++){
                if(map[x1][j])
                    merge(map[x1][j],i);
                else
                    map[x1][j]=i;
                if(map[x2][j])
                    merge(map[x2][j],i);
                else
                    map[x2][j]=i;    
            }
        }
        std::cout << sol;

    }

};
int main(){
    turtle tt;
    tt.find_sol();
    return 0;
}