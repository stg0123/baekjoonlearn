#include <iostream>
#include <vector>
using namespace std;
class rectangle{
private:
    vector<string> map;
    int N,M;
public:
    rectangle(){
        std::cin >> N >> M;
        map.resize(N);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> map[i];
    }
    bool check(int& size){
        for(int i=0;i<N-size;i++){
            for(int j=0;j<M-size;j++){
                if(map[i][j] == map[i+size][j] && map[i][j]==map[i][j+size] && map[i][j]==map[i+size][j+size])
                    return true;
            }
        }
        return false;
    }
    void find_sol(){
        int size = min(N,M);
        while(size>=0){
            if(check(size)){
                std::cout << (size+1)*(size+1)<< '\n';
                return ;
            }
        }
    }


};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    rectangle rt;
    rt.find_sol();
    return 0;
}