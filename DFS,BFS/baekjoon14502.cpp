#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
class lab{
private:
    vector<vector<int>> map;
    vector<pair<int,int>> z_loc,b_loc;
    vector<int> select;
    vector<int> maxloc;
    int N,M,max;
public :
    lab(int n,int m):N(n),M(m){
        map.resize(n);
        for(int i=0;i<n;i++)
            map[i].resize(m);
        select.resize(3,0);
        max=0;
    };

    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                std::cin >> map[i][j];
                if(map[i][j]==0)
                    z_loc.push_back(make_pair(i,j));
                else if(map[i][j]==2)
                    b_loc.push_back(make_pair(i,j));
            }
    };
    void start(){
        for(int i=0;i<z_loc.size()-2;i++)
            sel_loc(1,i);

    };
    void sel_loc(int level,int l){
        select[level-1]=l;
        if(level==3){
            dfs();
            return;
        }
        for(int i=l+1;i<z_loc.size();i++)
            sel_loc(level+1,i);
    };

    void dfs(){
        vector<vector<int>> copymap=map;
        for(int i=0;i<3;i++)
            copymap[z_loc[select[i]].first][z_loc[select[i]].second]=1;
        vector<pair<int,int>> copyb_loc=b_loc;
        int x,y;
        int sum=0;
        while(!copyb_loc.empty()){
            x=copyb_loc.back().first;
            y=copyb_loc.back().second;
            copyb_loc.pop_back();
            for(int i=0;i<4;i++){
                if(x+dx[i]>=0&&x+dx[i]<N&&y+dy[i]>=0&&y+dy[i]<M&&copymap[x+dx[i]][y+dy[i]]==0){
                    copymap[x+dx[i]][y+dy[i]]=2;
                    copyb_loc.push_back(make_pair(x+dx[i],y+dy[i]));
                    sum++;
                }
            }
        }
        if(max<(z_loc.size()-3)-sum){
            max=(z_loc.size()-3)-sum;
            //maxloc=select;
        }
    }
    
    void print_max(){
        std::cout << max<<'\n';
        //std::cout <<"loc:"<< maxloc[0]<<','<<maxloc[1]<<','<<maxloc[2]<<'\n';
    };


    void print_zloc(){
        for(int i=0;i<z_loc.size();i++)
            std::cout << z_loc[i].first << ','<<z_loc[i].second <<' ';
        std::cout <<'\n';
    }
};


int main(){
    int n,m;
    std::cin >> n >> m;
    lab l(n,m);
    l.set_val();
    l.start();
    l.print_max();
    return 0;
}