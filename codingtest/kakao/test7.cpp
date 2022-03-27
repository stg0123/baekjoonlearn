#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
class test7{
private:
    vector<vector<int>> map;
    pair<int,int> A_loc;
    pair<int,int> B_loc;
public:
    test7(vector<vector<int>> board,vector<int> aloc,vector<int> bloc):map(board){
        A_loc={aloc[0],aloc[1]};
        B_loc={bloc[0],bloc[2]};
    }
    int bfs(){
        queue<pair<int,int>> q;
        q.push(A_loc);
        q.push(B_loc);
        pair<int,int> cur;
        bool flag=false;
        int sol=0;
        int nx,ny;
        while(!q.empty()){
            cur =q.front();
            q.pop();
            bool check =flag;
            for(int i=0;i<4;i++){
                nx=cur.first+dx[i],ny=cur.second+dy[i];
                if(nx<map.size() && nx>=0 && ny<map[0].size() && ny >=0){
                    if(map[nx][ny]){
                        if(!flag && B_loc!=make_pair(nx,ny)){
                            q.push({nx,ny});
                            sol++;
                            flag=!flag;
                            break;
                        }
                        else if(flag && A_loc!=make_pair(nx,ny)){
                            q.push({nx,ny});
                            sol++;
                            flag=!flag;
                            break;
                        }
                    }
                } 
                if(check==flag)
                    break;
            }

            return sol;
        }
    }
    

};
int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    test7 t7(board,aloc,bloc);
    return t7.bfs();
}