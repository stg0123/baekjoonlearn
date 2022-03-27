#include <iostream>
#include <vector>
using namespace std;
class Z{
private:
    vector<vector<int>> map;
    int N;
    int r,c;
    int sol=0;
public:
    Z(){
        std::cin >> N >> r >> c;
    }
    void DC(int x,int y,int size){
        if(size==1)    
            return ;
        int nsize=size/2;
        if(x+nsize>r && y+nsize>c)    
            DC(x,y,nsize);
        else if(x+nsize>r&&y+nsize<=c){
            sol+=nsize*nsize;
            DC(x,y+nsize,nsize);
        }
        else if(x+nsize<=r&&y+nsize>c){
            sol+=nsize*nsize*2;
            DC(x+nsize,y,nsize);
        }
        else{
            sol+=nsize*nsize*3;
            DC(x+nsize,y+nsize,nsize);
        }
    }
    void find_sol(){
        DC(0,0,1<<N);
        std::cout << sol << '\n';
    }
};
int main(){
    Z z;
    z.find_sol();
    return 0;
}