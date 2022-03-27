#include <iostream>
#include <vector>
using namespace std;
class tetronomio{
private:
    vector<vector<int>> map;
    int N,M;
public:
    tetronomio(){
        std::cin >> N >> M ;
        map.resize(N,vector<int>(M));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                std::cin >> map[i][j];
    }
    void find_sol(){
        int MAX=0;
        int tmp;
        for(int i=0;i<N;i++){
            for(int j=0;j<M-3;j++){
                tmp=0;
                for(int l=0;l<4;l++)
                    tmp+=map[i][j+l];
                MAX=max(tmp,MAX);
            }
        }
        for(int i=0;i<N-1;i++){
            for(int j=0;j<M-2;j++){
                tmp=0;
                for(int l=0;l<3;l++)
                    tmp+=map[i][j+l];
                for(int l=0;l<3;l++)
                    MAX = max(tmp+map[i+1][j+l],MAX);
            }
            for(int j=0;j<M-1;j++){
                tmp=map[i][j]+map[i][j+1];
                if(j-1>=0)
                    MAX=max(tmp+map[i+1][j-1]+map[i+1][j],MAX);
                MAX=max(tmp+map[i+1][j]+map[i+1][j+1],MAX);
                if(j+2<M)
                    MAX=max(tmp+map[i+1][j+1]+map[i+1][j+2],MAX);
            }
            for(int j=0;j<M;j++){
                tmp=map[i][j];
                if(j-2>=0)
                    MAX=max(tmp+map[i+1][j-2]+map[i+1][j-1]+map[i+1][j],MAX);
                if(j-1>=0&&j+1<M)
                    MAX=max(tmp+map[i+1][j-1]+map[i+1][j]+map[i+1][j+1],MAX);
                if(j+2<M)
                    MAX=max(tmp+map[i+1][j]+map[i+1][j+1]+map[i+1][j+2],MAX);
            }
        }
        for(int i=0;i<N-2;i++){
            for(int j=0;j<M-1;j++){
                tmp=map[i][j]+map[i][j+1];
                MAX=max(tmp+map[i+1][j]+map[i+2][j],MAX);
                MAX=max(tmp+map[i+1][j+1]+map[i+2][j+1],MAX);
            }
            for(int j=0;j<M;j++){
                tmp=map[i][j];
                if(j-1>=0){
                    MAX=max(tmp+map[i+1][j-1]+map[i+1][j]+map[i+2][j-1],MAX);
                    MAX=max(tmp+map[i+1][j-1]+map[i+1][j]+map[i+2][j],MAX);
                    MAX=max(tmp+map[i+1][j]+map[i+2][j-1]+map[i+2][j],MAX);
                }
                if(j+1<M){
                    MAX=max(tmp+map[i+1][j]+map[i+1][j+1]+map[i+2][j],MAX);
                    MAX=max(tmp+map[i+1][j]+map[i+1][j+1]+map[i+2][j+1],MAX);
                    MAX=max(tmp+map[i+1][j]+map[i+2][j]+map[i+2][j+1],MAX);
                }
            }
        }
        for(int i=0;i<N-3;i++){
            for(int j=0;j<M;j++){
                tmp=0;
                for(int l=0;l<4;l++)
                    tmp+=map[i+l][j];
                MAX=max(tmp,MAX);
            }
        }
        std::cout << MAX <<"\n";
    }
};
int main(){
    tetronomio t1;
    t1.find_sol();

    return 0;
}