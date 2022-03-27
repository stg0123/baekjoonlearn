#include <iostream>
#include <vector>
using namespace std;
class candy{
private:
    vector<string> map;
    int N,sol;
public:
    candy(){
        std::cin >> N;
        map.resize(N);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> map[i];
        for(int i=0;i<N;i++){
            check(i,0,1);
            check(0,i,0);
        }
    }
    void check(int x,int y,bool loc){
        int t =0;
        char last=0;
        if(loc){
            for(int i=0;i<N;i++){
                if(last==map[x][i])    
                    t++;
                else{
                    last=map[x][i];
                    t=1;
                }
                sol=max(t,sol);
            }
        }
        else{
            for(int i=0;i<N;i++){
                if(last==map[i][y])
                    t++;
                else{
                    last=map[i][y];
                    t=1;
                }
                sol=max(t,sol);
            }
        }
    }
    void find_sol(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N-1;j++){
                swap(map[i][j],map[i][j+1]);
                check(i,0,1);
                check(0,j,0);
                check(0,j+1,0);
                swap(map[i][j],map[i][j+1]);
                if(i!=N-1){
                    swap(map[i][j],map[i+1][j]);
                    check(0,j,0);
                    check(i,0,1);
                    check(i+1,0,1);
                    swap(map[i][j],map[i+1][j]);
                }
            }
        }
        std::cout << sol << '\n';

    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    candy cd;
    cd.find_sol();
    return 0;
}