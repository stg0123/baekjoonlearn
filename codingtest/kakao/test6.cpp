#include <iostream>
#include <string>
#include <vector>
using namespace std;
class test6{
private:
    vector<vector<int>> map;
public:
    test6(vector<vector<int>>& board):map(board){
    }
    
    void attack(int r1,int c1,int r2,int c2,int degree){
        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                map[i][j]-=degree;
            }
        }
    };
    void hill(int r1,int c1,int r2,int c2,int degree){
        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                map[i][j]+=degree;
            }
        }
    };
    int find_sol(vector<vector<int>>& skill){
        int sol=0;
        for(int i=0;i<skill.size();i++){
            if(skill[i][0]==1)
                attack(skill[i][1],skill[i][2],skill[i][3],skill[i][4],skill[i][5]);
            if(skill[i][0]==2)
                hill(skill[i][1],skill[i][2],skill[i][3],skill[i][4],skill[i][5]);
        }
        for(int i=0;i<map.size();i++){
            for(int j=0;j<map[0].size();j++){
                if(map[i][j]>0)
                    sol++;
            }
        }
        return sol;
    }

};

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    test6 t6(board);
    return t6.find_sol(skill);
}