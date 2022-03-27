#include <iostream>
#include <vector>
using namespace std;
class _2048{
private:
    vector<vector<int>> map;
    int N;
    int MAX=0;
public:
    _2048(){
        std::cin >> N;
        map.resize(N,vector<int>(N));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++){
                std::cin >> map[i][j];
                if(map[i][j]>MAX)
                    MAX=map[i][j];
            }
    }
    vector<vector<int>> up(vector<vector<int>> m){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int l=1;
                if(!m[i][j]){
                    while(i+l<N){
                        if(m[i+l][j]){
                            m[i][j]=m[i+l][j];
                            m[i+l][j]=0; 
                            break;  
                        }
                        l++;
                    }
                }
                l=1;
                if(m[i][j]){
                    while(i+l<N){
                        if(m[i+l][j]){
                            if(m[i][j]==m[i+l][j]){
                                m[i][j]*=2;
                                m[i+l][j]=0;
                                if(m[i][j]>MAX)
                                    MAX=m[i][j];
                            }
                            break;
                        }
                        l++;
                    }   
                }
            }
        }
        return m;
    }
    vector<vector<int>> down(vector<vector<int>> m){
        for(int i=N-1;i>0;i--){
            for(int j=0;j<N;j++){
                int l=1;
                if(!m[i][j]){
                    while(i-l>=0){
                        if(m[i-l][j]){
                            m[i][j]=m[i-l][j];
                            m[i-l][j]=0;
                            break;
                        }
                        l++;
                    }
                }
                l=1;
                if(m[i][j]){
                    while(i-l>=0){
                        if(m[i-l][j]){
                            if(m[i][j]==m[i-l][j]){
                                m[i][j]*=2;
                                m[i-l][j]=0;
                                if(m[i][j]>MAX)
                                    MAX=m[i][j];
                            }
                            break;
                        }
                        l++;
                    }   
                }
            }
        }
        return m;
    }
    vector<vector<int>> left(vector<vector<int>> m){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                int l=1;
                if(!m[i][j]){
                    while(j+l<N){
                        if(m[i][j+l]){
                            m[i][j]=m[i][j+l];
                            m[i][j+l]=0;
                            break;
                        }
                        l++;
                    }
                }
                l=1;
                if(m[i][j]){
                    while(j+l<N){
                        if(m[i][j+l]){
                            if(m[i][j]==m[i][j+l]){
                                m[i][j]*=2;
                                m[i][j+l]=0;
                                if(m[i][j]>MAX)
                                    MAX=m[i][j];
                            }
                            break;
                        }
                        l++;
                    }   
                }
            }
        }
        return m;
    }
    vector<vector<int>> right(vector<vector<int>> m){
        for(int i=0;i<N;i++){
            for(int j=N-1;j>0;j--){
                int l=1;
                if(!m[i][j]){
                    while(j-l>=0){
                        if(m[i][j-l]){
                            m[i][j]=m[i][j-l];
                            m[i][j-l]=0;
                            break;
                        }
                        l++;
                    }
                }
                l=1;
                if(m[i][j]){
                    while(j-l>=0){
                        if(m[i][j-l]){
                            if(m[i][j]==m[i][j-l]){
                                m[i][j]*=2;
                                m[i][j-l]=0;
                                if(m[i][j]>MAX)
                                    MAX=m[i][j];
                            }
                            break;
                        }
                        l++;
                    }   
                }
            }
        }
        return m;
    }
    void print_map(vector<vector<int>> m){
        std::cout <<'\n';
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                std::cout << m[i][j]<<' ';
            }
            std::cout << '\n';
        }
    }
    void solve(vector<vector<int>> m,int t){
        if(t==5)
            return ;
        solve(up(m),t+1);
        solve(down(m),t+1);
        solve(left(m),t+1);
        solve(right(m),t+1);
    }
    void solution(){
        solve(map,0);
        std::cout << MAX<<'\n';
    }
    void test(){
        print_map(down(down(left(down(left(map))))));
    }
};

int main(){
    _2048 t1;
    t1.solution();
    return 0;
}