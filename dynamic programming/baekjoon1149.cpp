#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
class rgb{
private :
    vector<vector<int>> map;
    vector<vector<int>> color;
    int N;
public :
    rgb(int n):N(n){
        map.resize(3);
        for(int i=0;i<3;i++)
            map[i].resize(n,0);
            
        color.resize(3);
        for(int i=0;i<3;i++)
            color[i].resize(n,0);
    };

    int cal(int k,int l){
        int sol=0;
        if(map[k][l-1]!=0)
            return map[k][l-1];
        
        sol=min(cal((k+1)%3,l-1),cal((k+2)%3,l-1))+color[k][l-1];
        map[k][l-1]=sol;
        return sol;
    };
    void set_cost(){
        for(int j=0;j<N;j++)
            for(int i=0;i<3;i++)
                std::cin>>color[i][j];
        for(int i=0;i<3;i++)
            map[i][0]=color[i][0];
    };
    void print_cost(){
        for(int i=0;i<N;i++)
            std::cout << color[0][i]<<' '<<color[1][i]<<' '<< color[2][i]<<'\n';
    };
    
};
int main(){
    int n,min,a,b,c;
    std::cin >> n;
    rgb cal(n);
    cal.set_cost();
    a=cal.cal(0,n);
    b=cal.cal(1,n);
    c=cal.cal(2,n);
    if(a<b)
        min=a;
    else
        min=b;
    if(c<min)
        min=c;

    std::cout <<min;    
    
    return 0;
}