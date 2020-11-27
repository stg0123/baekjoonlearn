//11:13
#include <iostream>
#include <vector>

using namespace std;
class paper{
private :
    vector<vector<int>> map;
    int N;
    int m_z_o[3];
public :
    paper(int n):N(n){
        map.resize(n);
        for(int i=0;i<n;i++)
            map[i].resize(n,0);
        for(int i=0;i<3;i++)
            m_z_o[i]=0;

    };
    void set_paper(){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                std::cin >> map[i][j];

    };
    void print_paper(){
        std::cout <<'\n';
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                std::cout << map[i][j]<<' ';
            std::cout<< '\n'; 
        }
    };

    void dp(int x,int y,int l){
        int check=map[x][y];
        bool flag=false;
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++)
                if(map[x+i][y+j]!=check){
                    flag =true;
                    break;
                }
            if(flag==true)
                break;
        }
        if(flag==false){
            //std::cout << "x ,y, map[x][y],l="<<x<<','<<y<<','<<map[x][y]<<','<<l<<'\n';
            m_z_o[check+1]++;
        }else
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                    dp(x+i*l/3,y+j*l/3,l/3);
        
    };
    void print_result(){
        std::cout << m_z_o[0]<<'\n'<<m_z_o[1]<<'\n'<<m_z_o[2];
    }
};
int main(){
    int n;
    std::cin >> n;
    paper p(n);
    p.set_paper();
    p.dp(0,0,n);
    p.print_result();
    return 0;
}
