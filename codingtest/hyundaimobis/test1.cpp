#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class test1{
private:
    vector<int> target;
    vector<vector<int>> positions;
    int N=5,M=10;
public:
    test1(vector<int>& t,vector<vector<int>>& p):target(t),positions(p){
        
    }
    double distance(int x,int y){
        return sqrt(x*x+y*y);
    }
    void find_sol(){
        int sol=0;
        for(int i=0;i<M;i++){
            int length=0;
            for(int j=0;j<N;j++){
                length += target[j];
                if(distance(positions[i][0],positions[i][1])<=length){
                    sol+=10-i*2;
                    break;
                }
            }
        }
    }
};