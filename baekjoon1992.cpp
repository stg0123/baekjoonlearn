#include <iostream>
#include <vector>

using namespace std;
class quadtree{
private :
    vector<vector<int>> map;
    int N;

public :
    quadtree(int n):N(n){
        map.resize(n);
        for(int i=0;i<n;i++)
            map[i].resize(n,0);
    };
    
    void set_map(){
        char ch;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                std::cin >> ch;
                map[i][j]=ch-48;
            }
        }
    }

    void print_map(){
        std::cout << '\n';
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                std::cout << map[i][j];
            std::cout << '\n';
        }
    }

    void dq(int x,int y,int siz){
        int tmp =map[x][y];
        bool flag =false;
        for(int i=0;i<siz;i++){
            for(int j=0;j<siz;j++)
                if(tmp!=map[x+i][y+j]){
                    flag =true;
                    break;
                }
            if(flag)
                break;
        }
        if(flag==false)
            std::cout << map[x][y];
        else{
            int n=siz/2;
            std::cout <<'(';
            dq(x,y,n);
            dq(x,y+n,n);
            dq(x+n,y,n);
            dq(x+n,y+n,n);
            std::cout <<')';
        };
    }


};

int main(){
    int n;
    std::cin >> n;
    quadtree qt(n);
    qt.set_map();
    qt.dq(0,0,n);


    return 0;
}
