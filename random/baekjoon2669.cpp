#include <iostream>
#include <vector>
using namespace std;
class rectangle{
private:
    vector<vector<int>> map;
public:
    rectangle(){
        map.resize(100,vector<int>(100,0));
        set_val();
    }
    void set_val(){
        int x1,y1,x2,y2;
        for(int i=0;i<4;i++){
            std::cin >> x1 >> y1 >>x2 >> y2;
            for(int i=x1;i<x2;i++)
                for(int j=y1;j<y2;j++)
                    map[i][j]=1;

        }
    }
    void find_sol(){
        int sol =0;
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                sol+=map[i][j];
        std::cout << sol;
    }


};
int main(){
    rectangle rg;
    rg.find_sol();

    return 0;
}