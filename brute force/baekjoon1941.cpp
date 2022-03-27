#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
class princess{
private:
    vector<string> map;
    int N = 5;
public:
    princess(){
        map.resize(N);
        set_val();

    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> map[i];


    }
    bool check(vector<bool>& checked){
        int count=0;
        queue<pair<int,int>> q;
        vector<vector<bool>> visit(N,vector<bool>(N,false));
        for(int i=0;i<checked.size();i++){
            if(checked[i]){
                visit[i/N][i%N]=true;
                if(q.empty()){
                    visit[i/N][i%N]=false;
                    q.push({i/N,i%N});
                }
                if(map[i/N][i%N]=='S')
                    count++;
            }
        }
        if(count<4)
            return false;
        pair<int,int> cur;
        int nx,ny;
        count=0;
        while(!q.empty()){
            cur = q.front();
            q.pop();
            count ++;
            for(int i=0;i<4;i++){
                nx=cur.first+dx[i],ny=cur.second+dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<N){
                    if(visit[nx][ny]){
                        visit[nx][ny]=false;
                        q.push({nx,ny});
                    }
                }

            }
        }
        if(count == 7)
            return true;
        return false;
    }

    void find_sol(){
        vector<bool> checked(25,false);
        for(int i=0;i<7;i++)
            checked[i]=true;
        int sol =0;
        do{
            if(check(checked))
                sol++;

        }while(prev_permutation(checked.begin(),checked.end()));
        std::cout << sol << '\n';

    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    princess pc;
    pc.find_sol();

    return 0;
}