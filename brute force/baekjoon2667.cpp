#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};
class maps{
    private:
        vector<vector<char>> map;
        int N;
    public:
        maps(int n):N(n){
            this->map.resize(n);
            for(int i=0;i<n;i++)
                map[i].resize(n,'0');

        };

        void fillthemap(){
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                    std::cin >> map[i][j]; 
        };
        int N_view(){
            return N;
        }
        int map_view(int x,int y){
            return map[x][y]-48;
        };
};

int dfs(maps & map,int x,int y,vector<vector<bool>>& visit){
    if(map.map_view(x,y)==0||visit[x][y]==true)
        return 0;
    int count=0;
    visit[x][y]=true;
    count++;
    for(int i=0;i<4;i++)
        if(x+dx[i]>=0&&x+dx[i]<map.N_view()&&y+dy[i]>=0&&y+dy[i]<map.N_view())
            count += dfs(map,x+dx[i],y+dy[i],visit);
            
    return count;
};
int main(){
    int n;
    std::cin >> n;
    vector<vector<bool>> visit(n+1,vector<bool>(n+1,false));
    maps map(n);
    map.fillthemap();
    /*
    std::cout<<'\n';
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            std::cout << map.map_view(i,j);
        std::cout<<'\n';
    }
    */
    vector<int> dfs_num;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int a= dfs(map,i,j,visit);
            if(a>0)
                dfs_num.push_back(a);
        }
    std::sort(dfs_num.begin(),dfs_num.end());
    std::cout << dfs_num.size()<<'\n';
    for(int i=0;i<dfs_num.size();i++)
        std::cout <<dfs_num[i] <<'\n';
    
    return 0;
}