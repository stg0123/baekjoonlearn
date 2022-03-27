#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
class test1{
private:
    vector<string> maps;
    vector<vector<bool>> visit1,visit2;
    int N,M;
public:
    test1(vector<string> maps):maps(maps){
        N= maps.size();
        M= maps[0].size();
        visit1.resize(N,vector<bool>(M,false));
        visit2.resize(N,vector<bool>(M,false));
    }
    void bfs(pair<int,int> start){
        visit1[start.first][start.second]=true;
        visit2[start.first][start.second]=true;
        unordered_map<char,int> m;
        queue<pair<int,int>> q;
        q.push({start.first,start.second});
        pair<int,int> cur;
        int nx,ny;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            m[maps[cur.first][cur.second]]++;
            for(int i=0;i<4;i++){
                nx=cur.first+dx[i],ny=cur.second+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<M){
                    if(!visit1[nx][ny] && maps[nx][ny]!='.'){
                        visit1[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
        }
        int MAX_val=0;
        char MAX_idx='A';
        for(auto i : m){
            if(i.second>MAX_val ||(i.second==MAX_val && i.first>MAX_idx)){
                MAX_idx=i.first;
                MAX_val=i.second;
            }
        }
        q.push({start.first,start.second});
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(m[maps[cur.first][cur.second]]<MAX_val)
                maps[cur.first][cur.second]=MAX_idx;
            
            for(int i=0;i<4;i++){
                nx=cur.first+dx[i],ny=cur.second+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<M){
                    if(!visit2[nx][ny] && maps[nx][ny]!='.'){
                        visit2[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    int find_sol(){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!visit1[i][j]&& maps[i][j]!='.')
                    bfs({i,j});
            }
        }
        int sol=0;
        unordered_map<char,int> m;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                std::cout << maps[i][j];
                if(maps[i][j]!='.'){
                    m[maps[i][j]]++;
                    sol=max(sol,m[maps[i][j]]);
                }
            }
            std::cout << '\n';
        }
        return sol;
    }
};
int solution(vector<string> maps){
    test1 t1(maps);
    return t1.find_sol();

};
int main(){
    std::cout << solution({"AABCA.QA","AABC..QX","BBBC.Y..",".A...T.A","....EE..",".M.XXEXQ","KL.TBBBQ"})<<'\n';

    return 0;
}