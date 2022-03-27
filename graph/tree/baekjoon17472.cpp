#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct brige{
    int start,end;
    int dis;
};
bool compare_brige(brige& a,brige& b){
    return a.dis<b.dis;
};
class connect_island{
private:
    vector<vector<int>> map;
    vector<brige> info;
    vector<int> parent;
    int N,M;
    int island_num; // 맵 번호는 실제 맵 번호의 +1 로 해놈 처음 받은게 1이라 확인한걸 구별하기위해..
    int sol_min_dis;
public:
    connect_island(){
        std::cin >> N >> M ;
        map.resize(N);
        island_num=1;
        sol_min_dis=0;
        set_val();
        parent.resize(island_num,-1);
        
    }
    void set_val(){
        int n;
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                std::cin >> n;
                map[i].push_back(n);
            }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                if(map[i][j]==1){
                    island_num++;
                    bfs(i,j);
                }
        }
        pair<bool,brige> tmp;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]!=0){
                    tmp =width_brige_find(i,j);
                    if(tmp.first)
                        info.push_back(tmp.second);
                    tmp=height_brige_find(i,j);
                    if(tmp.first)
                        info.push_back(tmp.second);
                }
            }
        }
        sort(info.begin(),info.end(),compare_brige);
    }
    void bfs(int start_x,int start_y){
        queue<pair<int,int>> q;
        map[start_x][start_y]=island_num;
        q.push({start_x,start_y});
        int cur_x,cur_y,tmp_x,tmp_y;
        while(!q.empty()){
            cur_x=q.front().first;
            cur_y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                tmp_x=cur_x+dx[i];
                tmp_y=cur_y+dy[i];
                if(tmp_x>=0&&tmp_x<N&&tmp_y>=0&&tmp_y<M&&map[tmp_x][tmp_y]==1){
                    map[tmp_x][tmp_y]=island_num;
                    q.push({tmp_x,tmp_y});
                }
            }
        }
    }
    void print_map(){
        
        std::cout << '\n';
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                std::cout << map[i][j]<<' ';
            std::cout << '\n';
        }
    }
    pair<bool,brige> width_brige_find(int x,int y){
        int i=1;
        while(y+i<M){
            if(map[x][y+i]==0)
                i+=1;
            else if(i>2){
                return {true,{map[x][y]-1,map[x][y+i]-1,i-1}};
            }
            else
                return {false,{}};                
        }
        return {false,{}};
    };
    pair<bool,brige> height_brige_find(int x,int y){
        int i=1;
        while(x+i<N){
            if(map[x+i][y]==0)
                i+=1;
            else if(i>2){
                return {true,{map[x][y]-1,map[x+i][y]-1,i-1}};
            }
            else
                return {false,{}};
        }
        return {false,{}};
    };

    int find(int n){
        if(parent[n]<0)
            return n;
        return parent[n]=find(parent[n]);
    }
    void merge(int a,int b,int dis){
        int p_a=find(a);
        int p_b=find(b);
        if(p_a==p_b)
            return ;
        parent[p_b]=p_a;
        sol_min_dis+=dis;
        island_num--;
    }

    void cruscal(){
        for(int i=0;i<info.size();i++)
            merge(info[i].start,info[i].end,info[i].dis);
        if(island_num==2)
            std::cout << sol_min_dis<<'\n';
        else
            std::cout << -1 << '\n';
    }

};
int main(){
    connect_island ci;
    ci.cruscal();

    return 0;
}