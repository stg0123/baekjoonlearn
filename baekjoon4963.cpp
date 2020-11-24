#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,-1,1};

class land{
private :
    vector<vector<int>> map;
    vector<vector<bool>> visit;
    int N,M;
    int cal;
public:
    land(int n,int m):N(n),M(m){
        map.resize(n);
        visit.resize(n);
        for(int i=0;i<n;i++){
            map[i].resize(m,0);
            visit[i].resize(m,false);
        }
        cal=0;
    };
    void map_set(){
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                std::cin >> map[i][j];
            }
    };
    void print_map(){
        std::cout <<'\n';
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                std::cout << map[i][j]<<' ';
        std::cout <<'\n';
        }
    }
    
    void dfs(int x,int y){
        if(visit[x][y]==true||map[x][y]==0)
            return ;
        stack<pair<int,int>> st;
        pair<int,int> tmp;
        tmp.first=x;
        tmp.second=y;
        st.push(tmp);
        visit[x][y]=true;    
        int cx,cy;

        while(!st.empty()){
            cx=st.top().first;
            cy=st.top().second;
            st.pop();
            for(int i=0;i<8;i++)
                if(cx+dx[i]>=0&&cx+dx[i]<N&&cy+dy[i]>=0&&cy+dy[i]<M)
                    if(map[cx+dx[i]][cy+dy[i]]==1&&visit[cx+dx[i]][cy+dy[i]]==false){
                        tmp.first=cx+dx[i];
                        tmp.second=cy+dy[i];
                        st.push(tmp);
                        visit[cx+dx[i]][cy+dy[i]]=true;
                    }
        }
        cal++;
    }

    void print_cal(){
        std::cout << cal<<'\n';
    };

};

int main(){
    int w,h;
    while(1){    
        std::cin >> w>>h;
        if(w==0&&h==0)
            return 0;
        land ld(h,w);
        ld.map_set();
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                ld.dfs(i,j);
        ld.print_cal();
    }

    return 0;
}