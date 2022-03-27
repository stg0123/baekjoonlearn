#include <iostream>
#include <vector>
using namespace std;
int INF= 1000000000;
class gerimendering{
private:
    vector<vector<int>> map;
    int N;
public:
    gerimendering(){
        std::cin >> N;
        map.resize(N,vector<int>(N));
        set_val();    
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                std::cin >> map[i][j];
    }
    int check(int x,int y){
        int sol=INF;
        for(int d1=1;d1<N-1;d1++){
            if(y-d1<0)
                break;
            for(int d2=1;d2<N-1;d2++){
                if(x+d1+d2>=N || y+d2>=N)
                    break;
                vector<int> sum(6,0);
                int MAX=0,MIN=INF;
                for(int i=0;i<N;i++){
                    for(int j=0;j<N;j++){
                        if(x+y<=i+j && x+d2+y+d2>=i+j && x-y<=i-j && x+d1-(y-d1)>=i-j)
                            sum[5]+=map[i][j];
                        else if(i<x+d1 && j<=y )
                            sum[1]+=map[i][j];
                        else if(i<=x+d2 && j>y )
                            sum[2]+=map[i][j];
                        else if(i>=x+d1 && j<(y-d1+d2) )
                            sum[3]+=map[i][j];
                        else if(i>x+d2 && j>=(y-d1+d2) )
                            sum[4]+=map[i][j];
                    }
                }
                for(int i=1;i<=5;i++){
                    MAX=max(MAX,sum[i]);
                    MIN=min(MIN,sum[i]);
                }
                sol=min(MAX-MIN,sol);
            }
        }
        return sol;
    }
    void find_sol(){
        int sol=INF;
        for(int i=1;i<N;i++)
            for(int j=0;j<N-2;j++)
                sol = min(sol,check(i,j));
        std::cout << sol << '\n';
    }


};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    gerimendering gm;
    gm.find_sol();

    return 0;
}