#include <iostream>
#include <vector>
using namespace std;
class matrix{
private:
    vector<vector<bool>> check;
    int N,M;
    int check_num=0;
public:
    matrix(){
        std::cin >> N >> M;
        check.resize(N,vector<bool>(M,false));
        set_val();
    }
    void set_val(){
        vector<vector<char>> tmp(N,vector<char>(M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                std::cin >> tmp[i][j];
            }
        }
        char ck;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                std::cin >> ck;
                if(ck!=tmp[i][j]){
                    check[i][j]=true;
                    check_num++;
                }
            }                
        }
    }
    void print_check(){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++)
                std::cout << check[i][j] <<' ';
            std::cout << '\n';                   
        }
    }
    void find_sol(){
        if(check_num==0){
            std::cout<<0;
            return ;
        }
        if(N<3||M<3){
                std::cout << -1;
            return ;
        }
        check_num=0;
        for(int i=0;i<=N-3;i++){
            for(int j=0;j<=M-3;j++){
                if(check[i][j]){
                    for(int dx=0;dx<3;dx++){
                        for(int dy=0;dy<3;dy++){
                            check[i+dx][j+dy]=!check[i+dx][j+dy];
                            if(((i+dx==N-1&&dy==0)||(dx==0&&j+dy==M-1))&&check[i+dx][j+dy]){
                                std::cout <<-1;
                                return ;
                            }
                        }
                    }
                    check_num++;
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(check[i][j]){
                    std::cout << -1;
                    return ;
                }
            }
        }
        std::cout <<check_num;
    }

};
int main(){
    matrix ma;
    ma.find_sol();
    return 0;
}