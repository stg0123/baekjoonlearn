#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
class chess{
    private:
        vector<vector<char>> map;
        int N,M;
    public:
        chess(int n,int m):N(n),M(m){
            map.resize(n);
            for(int i=0;i<n;i++){
                map[i].resize(m,'W');
            }  
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    std::cin >> map[i][j];
        };
        ~chess(){
            for(int i=0;i<N;i++)
                map[i].clear();
            map.clear();
        };
/*
        void print(){
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++)
                    std::cout << map[i][j];
                std::cout << '\n';
            }
            return ;
        };
  */      
        int w_check(int x,int y){
            int count=0;
            for(int i=x;i<x+8;i++)
                for(int j=y;j<y+8;j++){
                    if(i%2==0){
                        if(j%2==0){
                            if(map[i][j]!='W')
                                count++;
                        }
                        else{
                            if(map[i][j]!='B')
                                count++;
                        }
                    }
                    else{
                        if(j%2==0){
                            if(map[i][j]!='B')
                                count++;
                        }
                        else{
                            if(map[i][j]!='W')
                                count++;
                        }
                    }
                }
            return count;
        };

        int b_check(int x,int y){
            int count=0;
            for(int i=x;i<x+8;i++)
                for(int j=y;j<y+8;j++){
                    if(i%2==0){
                        if(j%2==0){
                            if(map[i][j]!='B')
                                count++;
                        }
                        else{
                            if(map[i][j]!='W')
                                count++;
                        }
                    }
                    else{
                        if(j%2==0){
                            if(map[i][j]!='W')
                                count++;
                        }
                        else{
                            if(map[i][j]!='B')
                                count++;
                        }
                    }
                }
            return count;
        };
        int compare(int x,int y){
            int wc,bc;
            wc=w_check(x,y);
            bc=b_check(x,y);
            if(wc<bc)
                return wc;
            else
                return bc;
        };
};
int main(){
    int n,m,smallchange=100;
    std::cin >> n >> m;
    chess ch(n,m);


    for(int x=0;x<=n-8;x++)
        for(int y=0;y<=m-8;y++){
            int l = ch.compare(x,y);
            if(smallchange>l)
                smallchange=l;
        }
    std::cout << smallchange;
    return 0;
}